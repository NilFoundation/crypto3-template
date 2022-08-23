cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0028 NEW)
cmake_policy(SET CMP0057 NEW)

## Change path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/packages"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/share/modules/cmake")

include(CMConfig)
include(CMDeploy)
include(CMSetupVersion)

cm_workspace(bls-test)

#macro(cm_find_package NAME)
# if(NOT "${NAME}" MATCHES "^${CMAKE_WORKSPACE_NAME}_.*$" AND NOT "${NAME}" STREQUAL CM)
#  find_package(${ARGV})
# else()
#  set(${ARGV0}_FOUND ON CACHE BOOL "")
# endif()
#endmacro()

#option(BUILD_TESTS "Build unit tests" TRUE)
#option(BUILD_SHARED_LIBS "Build shared library" TRUE)

add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/libs")
add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/bin")
add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/libs/marshalling")


#add_custom_target(bls-sig
#        COMMAND truffle compile
#        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/share/aux-proof-verify)

#configure_file(${CMAKE_CURRENT_LIST_DIR}/docs/doxygen/${CMAKE_WORKSPACE_NAME}.doxyfile.in
#        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_WORKSPACE_NAME}.doxyfile @ONLY)