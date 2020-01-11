cmake_minimum_required(VERSION 3.10)

project(SnmpB VERSION 1.1 LANGUAGES CXX)

option(STATIC_LINK_QT "Link in the Qt framework statically into SnmpB" OFF)

option(USE_BUNDLED_LIBSMI "Compile with bundled patched libsmi (RECOMMENDED)" ON)
option(STATIC_LINK_LIBSMI "Link in libsmi statically into SnmpB" ${USE_BUNDLED_LIBSMI})

option(USE_BUNDLED_TOMCRYPT "Compile with bundled libtomcrypt" OFF)
option(STATIC_LINK_TOMCRYPT "Link in libtomcrypt statically into SnmpB" ${USE_BUNDLED_TOMCRYPT})

#-- Prerequisite checking

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(PkgConfig REQUIRED)

pkg_check_modules(OPENSSL openssl) # FIXME

include(ExternalProject)

set(PATCH_DIR "${SnmpB_SOURCE_DIR}/patches")

find_program(PATCH NAMES patch DOC "POSIX patch(1) program for applying patches")


#-- ===== libsmi ===== --#

if(NOT USE_BUNDLED_LIBSMI)
    pkg_check_modules(SMI REQUIRED libsmi)

    if (STATIC_LINK_LIBSMI)
        add_library(libsmi STATIC IMPORTED)
    else()
        add_library(libsmi SHARED IMPORTED)
    endif()

else() # USE_BUNDLED_LIBSMI

    externalproject_add(libsmi
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libsmi

        URL https://www.ibr.cs.tu-bs.de/projects/libsmi/download/libsmi-0.5.0.tar.gz
        URL_HASH SHA224=5448d442c761e776905fb60f064a2ec3b1e26c0df145ee76cfed0e00

        PATCH_COMMAND ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0001-Original-fixes-by-Martin.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0002-automake-1.15-regen.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0003-automake-1.15.1-regen.patch"

        #-- NOTE: use `autoreconf` to regenerate the configure script and Makefile.in's
        CONFIGURE_COMMAND
            ${SnmpB_SOURCE_DIR}/libsmi/configure
               --prefix=/libsmi-prefix
               --enable-silent-rules

        INSTALL_COMMAND make DESTDIR=${SnmpB_BINARY_DIR} install

        #-- FIXME proper out-of-source build doesn't work here;
        #-- the FLEX/BISON calls in libsmi/lib/Makefile.am need some tweaking
        BUILD_IN_SOURCE TRUE
        )
endif()

#-- ===== libtomcrypt ===== --#

if(NOT USE_BUNDLED_TOMCRYPT)
    pkg_check_modules(TOMCRYPT REQUIRED libtomcrypt)

    if (STATIC_LINK_TOMCRYPT)
        add_library(libtomcrypt STATIC IMPORTED)
    else()
        add_library(libtomcrypt SHARED IMPORTED)
    endif()

else() # USE_BUNDLED_LIBTOMCRYPT

    externalproject_add(libtomcrypt
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libtomcrypt
        URL https://github.com/libtom/libtomcrypt/archive/1.17.tar.gz
        URL_HASH SHA224=03d8eadde5d0959679a22fdf9f98777b9d92197041a211ad49cc94cd

        PATCH_COMMAND ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0001-Original-tweaks-by-Martin.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0002-File-ownership-EUID-EGID.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0003-Include-used-definitions.patch"

        CONFIGURE_COMMAND ""

        BUILD_COMMAND make library
        BUILD_IN_SOURCE TRUE

        #TEST_COMMAND

        INSTALL_COMMAND
            make
                DESTDIR=${SnmpB_BINARY_DIR}/libtomcrypt-prefix
                NODOCS=1
            install
        )
endif()

#-- ===== SNMP++ lib ===== --#

externalproject_add(snmpxx
    SOURCE_DIR ${SnmpB_SOURCE_DIR}/snmp++

    #URL https://www.agentpp.com/download/snmp++-3.3.11a.tar.gz
    #URL_HASH SHA1=d7fff32791596e678a64c22acd5fc2a68d2cbe1e

    CONFIGURE_COMMAND
        ${SnmpB_SOURCE_DIR}/snmp++/configure
            --enable-silent-rules
            --with-tomcrypt
            --with-libtomcrypt-prefix=${SnmpB_BINARY_DIR}/libtomcrypt-prefix/usr
            #--with-libssl
            #--with-libssl-prefix=

    #PATCH_COMMAND <>
    # TODO review changes & update:
    # + more auth algos
    # + fixed memleak
    # - HMAC-SHA2-* algos with OpenSSL only, not with tomcrypt
    # ? INVALID_SOCKET redefined
    # - IPv6Utility.cpp inet_pton
    # + OpenSSL EVP API for md5/sha1
    # - std::auto_ptr instead of std::unique_ptr
    # - ctr64 MAX_INT weirdness
    # - notifyqueue.cpp set_notify_callback_fd big chunk
    # - usm_v3.cpp SAFE_ULONG_CAST ??
    )
add_dependencies(snmpxx libtomcrypt)

add_subdirectory(app)

message("")
message("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --")
message(STATUS "")
message(STATUS "SnmpB version ............. ${SnmpB_VERSION}")
message(STATUS "Qt5Widgets version ........ ${Qt5Widgets_VERSION}")
message("")
message("To start the build:")
message("    cmake --build ${CMAKE_BINARY_DIR}")
message("")
message("To fine-tune build config:")
message("    ccmake ${CMAKE_BINARY_DIR}")
message("")
message("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --")
