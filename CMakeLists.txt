cmake_minimum_required(VERSION 3.10)

project(SnmpB VERSION 1.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SMI REQUIRED libsmi)
pkg_check_modules(TOMCRYPT REQUIRED libtomcrypt)
#-- OpenSSL | libdes | libtomcrypt

include(ExternalProject)

set(PATCH_DIR "${SnmpB_SOURCE_DIR}/patches")

find_program(PATCH NAMES patch DOC "POSIX patch(1) program for applying patches")

externalproject_add(libsmi
    SOURCE_DIR ${SnmpB_SOURCE_DIR}/libsmi

    URL https://www.ibr.cs.tu-bs.de/projects/libsmi/download/libsmi-0.5.0.tar.gz
    URL_HASH SHA224=5448d442c761e776905fb60f064a2ec3b1e26c0df145ee76cfed0e00

    PATCH_COMMAND ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0001-Original-fixes-by-Martin.patch"
    COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0002-automake-1.15-regen.patch"
    COMMAND       ${PATCH} -p1 < "${PATCH_DIR}/libsmi/0003-automake-1.15.1-regen.patch"

    #-- NOTE: use `autoreconf` to regenerate the configure script and Makefile.in's
    CONFIGURE_COMMAND ${SnmpB_SOURCE_DIR}/libsmi/configure --prefix=/

    INSTALL_COMMAND make DESTDIR=${SnmpB_BINARY_DIR}/libsmi-prefix install

    #-- FIXME proper out-of-source build doesn't work here;
    #-- the FLEX/BISON calls in libsmi/lib/Makefile.am need some tweaking
    BUILD_IN_SOURCE TRUE
    )

#externalproject_add(libtomcrypt
#    SOURCE_DIR ${SnmpB_SOURCE_DIR}/libtomcrypt
#    )

externalproject_add(snmpxx
    SOURCE_DIR ${SnmpB_SOURCE_DIR}/snmp++
    CONFIGURE_COMMAND ${SnmpB_SOURCE_DIR}/snmp++/configure
    #PATCH_COMMAND <>
    #URL https://www.agentpp.com/download/snmp++-3.3.11a.tar.gz
    #URL_HASH SHA1=d7fff32791596e678a64c22acd5fc2a68d2cbe1e
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
