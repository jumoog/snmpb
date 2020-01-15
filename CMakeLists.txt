cmake_minimum_required(VERSION 3.10)

project(SnmpB VERSION 1.1 LANGUAGES CXX)

option(STATIC_LINK_QT "Link in the Qt framework statically into SnmpB" OFF)

option(USE_BUNDLED_LIBSMI "Compile with bundled patched libsmi (RECOMMENDED)" ON)
option(STATIC_LINK_LIBSMI "Link in libsmi statically into SnmpB" ${USE_BUNDLED_LIBSMI})

option(USE_BUNDLED_TOMCRYPT "Compile with bundled libtomcrypt" OFF)
option(STATIC_LINK_TOMCRYPT "Link in libtomcrypt statically into SnmpB" ${USE_BUNDLED_TOMCRYPT})

option(USE_BUNDLED_SNMPXX "Compile with bundled snmp++ library (RECOMMENDED)" ON)
option(STATIC_LINK_SNMPXX "Link in snmp++ statically into SnmpB" ${USE_BUNDLED_SNMPXX})

option(USE_BUNDLED_QWT "Compile with bundled QWT" OFF)
option(STATIC_LINK_QWT "Link in QWT statically into SnmpB" ${USE_BUNDLED_QWT})

list(APPEND CMAKE_MODULE_PATH "${SnmpB_SOURCE_DIR}/cmake")

#-- Prerequisite checking

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(PkgConfig REQUIRED)

pkg_check_modules(OPENSSL openssl) # FIXME

include(ExternalProject)

set(PATCH_DIR ${SnmpB_SOURCE_DIR}/patches)
set(PATCH_APP
    -DPATCH=${PATCH}
    -DPATCH_DIR=${PATCH_DIR}
    -P ${SnmpB_SOURCE_DIR}/cmake/patch-applier.cmake)
include(patch-applier)


#-- ===== libsmi ===== --#

pkg_check_modules(LIBSMI libsmi)
if(LIBSMI_FOUND)
    #-- The common libsmi 0.4.8 uses C++ keyword "class" as arg name in its headers.
    #-- Of course this doesn't roll, like so:
    #
    # /usr/include/smi.h:464:60: error: expected ‘,’ or ‘...’ before ‘class’
    # extern SmiClass *smiGetClass(SmiModule *smiModulePtr,char *class);
    #                                                           ^~~~~
    #-- As such, libsmi 0.4.8 isn't good enough; update to 0.5.0.
    if(LIBSMI_VERSION VERSION_LESS_EQUAL "0.4.8" AND NOT USE_BUNDLED_LIBSMI)
        message(FATAL_ERROR "libsmi 0.4.8 is no good. Update it, or switch to \
            bundled patched version: -DUSE_BUNDLED_LIBSMI=ON")
    endif()

    #-- Decent libsmi? Good, let's try that.
    set(USE_BUNDLED_LIBSMI "OFF" CACHE BOOL
        "Compile with bundled patched libsmi (RECOMMENDED)")
endif()

if (NOT USE_BUNDLED_LIBSMI)

    if (STATIC_LINK_LIBSMI)
        add_library(libsmi STATIC IMPORTED)
        set_property(TARGET libsmi
            INTERFACE_LINK_OPTIONS "${LIBSMI_STATIC_LDFLAGS}"
            )
    else()
        add_library(libsmi SHARED IMPORTED)
        set_property(TARGET libsmi
            INTERFACE_LINK_OPTIONS "${LIBSMI_LDFLAGS}"
            )
    endif()

    set_target_properties(libsmi PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${LIBSMI_INCLUDE_DIRS}"
        )

    set(USE_WHICH_LIBSMI "[system] libsmi ${LIBSMI_VERSION} from ${LIBSMI_PREFIX}")

else() # USE_BUNDLED_LIBSMI

    externalproject_add(libsmi-bundled
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libsmi
        PREFIX libsmi-prefix

        URL https://www.ibr.cs.tu-bs.de/projects/libsmi/download/libsmi-0.5.0.tar.gz
        URL_HASH SHA224=5448d442c761e776905fb60f064a2ec3b1e26c0df145ee76cfed0e00

        PATCH_COMMAND
        ${CMAKE_COMMAND} -DFILE=libsmi/0001-Original-fixes-by-Martin.patch ${PATCH_APP}
        COMMAND
        ${CMAKE_COMMAND} -DFILE=libsmi/0002-automake-1.15-regen.patch ${PATCH_APP}
        COMMAND
        ${CMAKE_COMMAND} -DFILE=libsmi/0003-automake-1.15.1-regen.patch ${PATCH_APP}
        COMMAND
        ${CMAKE_COMMAND} -DFILE=libsmi/0004-regenerate-bison-parsers.patch -DFLAG=-p2 ${PATCH_APP}

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

    # hack to avoid gnarly configure error
    file(MAKE_DIRECTORY ${SnmpB_BINARY_DIR}/libsmi-prefix/include)

    add_library(libsmi STATIC IMPORTED)
    add_dependencies(libsmi libsmi-bundled)
    set_target_properties(libsmi PROPERTIES
        IMPORTED_LOCATION
            ${SnmpB_BINARY_DIR}/libsmi-prefix/lib/libsmi.a
        INTERFACE_INCLUDE_DIRECTORIES
            ${SnmpB_BINARY_DIR}/libsmi-prefix/include
        )

    set(USE_WHICH_LIBSMI "[bundled] libsmi 0.5.0 + patches")
endif()

#-- ===== libtomcrypt ===== --#

pkg_check_modules(TOMCRYPT libtomcrypt)

if (NOT TOMCRYPT_FOUND)
    set(USE_BUNDLED_TOMCRYPT ON CACHE BOOL "Compile with bundled libtomcrypt" FORCE)
endif()

if(NOT USE_BUNDLED_TOMCRYPT)
    pkg_check_modules(TOMCRYPT REQUIRED libtomcrypt)

    if (STATIC_LINK_TOMCRYPT)
        add_library(libtomcrypt STATIC IMPORTED)
    else()
        add_library(libtomcrypt SHARED IMPORTED)
    endif()

    message(FATAL_ERROR "IMPLEMENT ME")

    set(USE_WHICH_TOMCRYPT "[system] libtomcrypt ${TOMCRYPT_VERSION} from ${TOMCRYPT_PREFIX}")

else() # USE_BUNDLED_LIBTOMCRYPT

    externalproject_add(libtomcrypt-bundled
        SOURCE_DIR ${SnmpB_SOURCE_DIR}/libtomcrypt
        PREFIX libtomcrypt-prefix
        URL https://github.com/libtom/libtomcrypt/archive/1.17.tar.gz
        URL_HASH SHA224=03d8eadde5d0959679a22fdf9f98777b9d92197041a211ad49cc94cd

        PATCH_COMMAND
        ${CMAKE_COMMAND} -DFILE=libtomcrypt/0001-Original-tweaks-by-Martin.patch ${PATCH_APP}
        COMMAND
        ${CMAKE_COMMAND} -DFILE=libtomcrypt/0002-File-ownership-EUID-EGID.patch ${PATCH_APP}
        COMMAND
        ${CMAKE_COMMAND} -DFILE=libtomcrypt/0003-Include-used-definitions.patch ${PATCH_APP}

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

    # hack to avoid gnarly configure error
    file(MAKE_DIRECTORY ${SnmpB_BINARY_DIR}/libtomcrypt-prefix/include)

    add_library(libtomcrypt STATIC IMPORTED)
    add_dependencies(libtomcrypt libtomcrypt-bundled)
    set_target_properties(libtomcrypt PROPERTIES
        IMPORTED_LOCATION
            ${SnmpB_BINARY_DIR}/libtomcrypt-prefix/lib/libtomcrypt.a
        INTERFACE_INCLUDE_DIRECTORIES
            ${SnmpB_BINARY_DIR}/libtomcrypt-prefix/include
        )

    set(USE_WHICH_TOMCRYPT "[bundled] libtomcrypt 1.17 + tweaks")

endif()

#-- ===== SNMP++ lib ===== --#

if (NOT USE_BUNDLED_SNMPXX)

    message(FATAL_ERROR "IMPLEMENT ME")

endif()

if (USE_BUNDLED_TOMCRYPT)
    set(SNMPXX_TOMCRYPT_OPT
        --with-tomcrypt
        --with-libtomcrypt-prefix=${SnmpB_BINARY_DIR}/libtomcrypt-prefix
        --enable-shared=OFF
        LINKFLAGS=${TOMCRYPT_STATIC_LDFLAGS}
        )
else ()
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

# hack to avoid gnarly configure error
file(MAKE_DIRECTORY ${SnmpB_BINARY_DIR}/snmpxx-prefix/include)

add_library(snmpxx STATIC IMPORTED)
add_dependencies(snmpxx snmpxx-bundled)
set_target_properties(snmpxx PROPERTIES
    IMPORTED_LOCATION
        ${SnmpB_BINARY_DIR}/snmpxx-prefix/lib/libsnmp++.a
    INTERFACE_INCLUDE_DIRECTORIES
        ${SnmpB_BINARY_DIR}/snmpxx-prefix/include
    )

#-- ===== QWT widgets ===== --#

if(NOT USE_BUNDLED_QWT)
    add_library(qwt SHARED IMPORTED)
    set_target_properties(qwt PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES /usr/include/qwt
        IMPORTED_LOCATION /usr/lib/libqwt-qt5.so.6
        )
else() # USE_BUNDLED_QWT
    # TODO
    message(FATAL_ERROR "IMPLEMENT ME")
endif()

#-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --#

add_subdirectory(app)

message("")
message("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --")
message(STATUS "")
message(STATUS "SnmpB version ............. ${SnmpB_VERSION}")
message(STATUS "Qt5Widgets version ........ ${Qt5Widgets_VERSION}")
message(STATUS "SMI library ............... ${USE_WHICH_LIBSMI}")
message(STATUS "TomCrypt .................. ${USE_WHICH_TOMCRYPT}")
message("")
message("To start the build:")
message("    cmake --build ${CMAKE_BINARY_DIR}")
message("")
message("To fine-tune build config:")
message("    ccmake ${CMAKE_BINARY_DIR}")
message("")
message("-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --")
