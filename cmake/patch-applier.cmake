#-- patch-applier.cmake by ulidtko 2020
#
#-- Apply the classic Unified Diff patches in idempotent, CMake-friendly manner.
#
#-- How to use:
#
#    1) put patch-applier.cmake (this file) under CMAKE_MODULE_PATH
#
#    2) add include call in top-level CMakeLists.txt:
#
#       include(patch-applier)
#
#    3) invoke in your ADD_CUSTOM_COMMAND, ExternalProject_Add or elsewhere:
#
#       ${CMAKE_COMMAND} -DFILE=foo.patch -P patch-applier.cmake
#       ${CMAKE_COMMAND} -DFILE=foo.patch -DFLAG=-p0 -P patch-applier.cmake
#
#-- The script will correctly succeed if the patch has already been applied.
#
#-- Non-absolute FILE arguments are resolved relative to PATCH_DIR.
#
#-- The initial include() call is necessary for configure-time checking.

#-- FIXME: https://gitlab.kitware.com/cmake/cmake/issues/16854 is causing grief.

set(PATCH_TIMEOUT 2.5) # seconds

if(NOT CMAKE_SCRIPT_MODE_FILE)
    #-- we're include()-ed at configure-time

    find_program(PATCH NAMES patch DOC "POSIX patch(1) program for applying patches")

else()
    #-- we're invoked as -P script (build-time)
    if(NOT FLAG)
        set(FLAG "-p1")
    endif()

    if(NOT FILE)
        message(SEND_ERROR "patch-applier.cmake: expected input via -DFILE=input.patch")
        return()
    endif()

    get_filename_component(FILEABS ${FILE} ABSOLUTE BASE_DIR ${PATCH_DIR})

    set(CMD_CK ${PATCH} -r- --reverse --dry-run ${FLAG} -i ${FILEABS})
    set(CMD_DO ${PATCH} -r- --forward           ${FLAG} -i ${FILEABS})

    message(STATUS "Checking if already applied: ${FILE}")

    execute_process(COMMAND ${CMD_CK}
        TIMEOUT ${PATCH_TIMEOUT}
        OUTPUT_QUIET ERROR_QUIET
        RESULT_VARIABLE CHECK_EXITCODE
        )
    if(CHECK_EXITCODE EQUAL 0)
        # can smoothly apply in reverse -- already applied -- success exit
        message(STATUS "Detected is already applied: ${FILE}")
        return()
    endif()

    message(STATUS "Applying ${FILE}")

    execute_process(COMMAND ${CMD_DO}
        TIMEOUT ${PATCH_TIMEOUT}
        RESULT_VARIABLE DO_EXITCODE
        )
    #if(NOT DO_EXITCODE EQUAL 0)
    #    message(FATAL_ERROR "Patch command nonzero exit: ${CMD_DO}")
    #endif()
endif()
