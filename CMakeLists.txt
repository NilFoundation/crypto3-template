cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

cmake_policy(SET CMP0042 NEW)
cmake_policy(SET CMP0028 NEW)
cmake_policy(SET CMP0057 NEW)

## Change path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/packages"
        "${CMAKE_CURRENT_LIST_DIR}/cmake/modules/share/modules/cmake")

include(CMConfig)



project(bls-test)

add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/libs")
add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/bin")
add_subdirectories("${CMAKE_CURRENT_LIST_DIR}/libs/marshalling")