cmake_minimum_required(VERSION 3.10)

project(SnmpB VERSION 1.1 LANGUAGES CXX)

option(STATIC_LINK_QT "Link in the Qt framework statically into SnmpB" OFF)

option(USE_BUNDLED_LIBSMI "Compile with bundled patched libsmi (RECOMMENDED)" ON)
option(STATIC_LINK_LIBSMI "Link in libsmi statically into SnmpB" ${USE_BUNDLED_LIBSMI})

option(USE_BUNDLED_TOMCRYPT "Compile with bundled libtomcrypt" OFF)
option(STATIC_LINK_TOMCRYPT "Link in libtomcrypt statically into SnmpB" ${USE_BUNDLED_TOMCRYPT})

#-- Prerequisite checking

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

    externalproject_add(libsmi-bundled
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libsmi
        PREFIX libsmi-prefix

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

        BUILD_BYPRODUCTS
            ${SnmpB_BINARY_DIR}/libsmi-prefix/lib/libsmi.a
            ${SnmpB_BINARY_DIR}/libsmi-prefix/include/smi.h

        INSTALL_COMMAND make DESTDIR=${SnmpB_BINARY_DIR} install

        #-- FIXME proper out-of-source build doesn't work here;
        #-- the FLEX/BISON calls in libsmi/lib/Makefile.am need some tweaking
        BUILD_IN_SOURCE TRUE
        )
    add_library(libsmi STATIC IMPORTED)
    add_dependencies(libsmi libsmi-bundled)
    set_target_properties(libsmi PROPERTIES
        IMPORTED_LOCATION
            ${SnmpB_BINARY_DIR}/libsmi-prefix/lib/libsmi.a
        INTERFACE_INCLUDE_DIRECTORIES
            ${SnmpB_SOURCE_DIR}/libsmi/lib
            #${SnmpB_BINARY_DIR}/libsmi-prefix/include # FIXME builds OK, but...
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

    externalproject_add(libtomcrypt-bundled
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libtomcrypt
        PREFIX libtomcrypt-prefix
        URL https://github.com/libtom/libtomcrypt/archive/1.17.tar.gz
        URL_HASH SHA224=03d8eadde5d0959679a22fdf9f98777b9d92197041a211ad49cc94cd

        PATCH_COMMAND ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0001-Original-tweaks-by-Martin.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0002-File-ownership-EUID-EGID.patch"
        COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libtomcrypt/0003-Include-used-definitions.patch"

        CONFIGURE_COMMAND "" # uses plain Makefiles

        BUILD_COMMAND
            make
                "CFLAGS=-fpic\ -DLTC_NO_ROLC\ -Isrc/headers"
            library
        BUILD_IN_SOURCE TRUE

        #TEST_COMMAND # TODO it has a test suite

        INSTALL_COMMAND
            make
                DESTDIR=${SnmpB_BINARY_DIR}/libtomcrypt-prefix
                LIBPATH=/lib
                INCPATH=/include
                DATAPATH=/share/doc/libtomcrypt
                NODOCS=1
            install
        )
    add_library(libtomcrypt STATIC IMPORTED)
    add_dependencies(libtomcrypt libtomcrypt-bundled)
    set_target_properties(libtomcrypt PROPERTIES
        IMPORTED_LOCATION
            ${SnmpB_BINARY_DIR}/libtomcrypt-prefix/lib/libtomcrypt.a
        INTERFACE_INCLUDE_DIRECTORIES
            ${SnmpB_BINARY_DIR}/libtomcrypt-prefix/include
        )
endif()

#-- ===== SNMP++ lib ===== --#

if (USE_BUNDLED_TOMCRYPT)
    set(SNMPXX_TOMCRYPT_OPT
        --with-tomcrypt
        --with-libtomcrypt-prefix=${SnmpB_BINARY_DIR}/libtomcrypt-prefix
        --enable-shared=OFF
        )
else () # use system libtomcrypt.
    set(SNMPXX_TOMCRYPT_OPT
        --with-tomcrypt
        --with-libtomcrypt-prefix=${TOMCRYPT_PREFIX}
        --enable-static=OFF
        LINKFLAGS=${TOMCRYPT_LDFLAGS}
        )
endif()

externalproject_add(snmpxx-bundled
    SOURCE_DIR ${SnmpB_SOURCE_DIR}/snmp++
    PREFIX snmpxx-prefix

    #URL https://www.agentpp.com/download/snmp++-3.3.11a.tar.gz
    #URL_HASH SHA1=d7fff32791596e678a64c22acd5fc2a68d2cbe1e

    CONFIGURE_COMMAND
        ${SnmpB_SOURCE_DIR}/snmp++/configure
            --prefix=/
            --enable-silent-rules
            --disable-threads # FIXME
            ${SNMPXX_TOMCRYPT_OPT}
            #--with-libssl
            #--with-libssl-prefix=

    BUILD_BYPRODUCTS
        ${SnmpB_BINARY_DIR}/snmpxx-prefix/lib/libsnmp++.a
        ${SnmpB_BINARY_DIR}/snmpxx-prefix/include/snmp_pp/snmp_pp.h

    INSTALL_COMMAND
        make
            DESTDIR=${SnmpB_BINARY_DIR}/snmpxx-prefix
        install

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
add_dependencies(snmpxx-bundled libtomcrypt)

add_library(snmpxx STATIC IMPORTED)
add_dependencies(snmpxx snmpxx-bundled)
set_target_properties(snmpxx PROPERTIES
    IMPORTED_LOCATION
        ${SnmpB_BINARY_DIR}/snmpxx-prefix/lib/libsnmp++.a
    INTERFACE_INCLUDE_DIRECTORIES
        ${SnmpB_SOURCE_DIR}/snmp++/include
        #${SnmpB_BINARY_DIR}/snmpxx-prefix/include # FIXME builds OK, but...
    )

#-- ===== QWT widgets ===== --#

# FIXME
add_library(qwt SHARED IMPORTED)
set_target_properties(qwt PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES /usr/include/qwt
    IMPORTED_LOCATION /usr/lib/libqwt-qt5.so.6
    )

#-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --#

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
