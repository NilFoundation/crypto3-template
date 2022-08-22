cmake_minimum_required(VERSION 3.14 FATAL_ERROR)


cm_project(bls-test WORKSPACE_NAME ${CMAKE_WORKSPACE_NAME} LANGUAGES ASM C CXX)
#cmake_policy(SET CMP0042 NEW)
#cmake_policy(SET CMP0028 NEW)
#cmake_policy(SET CMP0057 NEW)

cm_find_package(CM)
include(CMDeploy)
include(CMSetupVersion)



 list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/packages"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/share/modules/cmake")

cm_workspace(bls-test)

#include(CMConfig)
#include(CMDeploy)
#include(CMSetupVersion)

add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/libs")

add_executable(${CURRENT_PROJECT_NAME} main.cpp)


target_link_libraries(${CURRENT_PROJECT_NAME}
        crypto3::algebra
        crypto3::block
        crypto3::hash
        crypto3::multiprecision
        crypto3::pubkey
        crypto3::random
)





#option(BUILD_TESTS "Build unit tests" TRUE)
#option(BUILD_SHARED_LIBS "Build shared library" TRUE)



#add_custom_target(aux-proof-verify
#        COMMAND truffle compile
#        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/share/aux-proof-verify)

#configure_file(${CMAKE_CURRENT_LIST_DIR}/docs/doxygen/${CMAKE_WORKSPACE_NAME}.doxyfile.in
#        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_WORKSPACE_NAME}.doxyfile @ONLY)