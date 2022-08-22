cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(bls-test)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/libs/pubkey")

#cmake_policy(SET CMP0042 NEW)
#cmake_policy(SET CMP0028 NEW)
#cmake_policy(SET CMP0057 NEW)


# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake"
#        "${CMAKE_CURRENT_LIST_DIR}/cmake/packages"
#        "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/share/modules/cmake")

#include(CMConfig)
#include(CMDeploy)
#include(CMSetupVersion)

#cm_workspace(mina)



#option(BUILD_TESTS "Build unit tests" TRUE)
#option(BUILD_SHARED_LIBS "Build shared library" TRUE)



#add_custom_target(aux-proof-verify
#        COMMAND truffle compile
#        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/share/aux-proof-verify)

#configure_file(${CMAKE_CURRENT_LIST_DIR}/docs/doxygen/${CMAKE_WORKSPACE_NAME}.doxyfile.in
#        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_WORKSPACE_NAME}.doxyfile @ONLY)