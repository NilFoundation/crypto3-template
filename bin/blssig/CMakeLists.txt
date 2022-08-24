cmake_minimum_required(VERSION 3.5)


cm_project(bls-test WORKSPACE_NAME ${CMAKE_WORKSPACE_NAME} LANGUAGES ASM C CXX)

# get header files; only needed by CMake generators,
# expr.g., for creating proper Xcode projects
set(${CURRENT_PROJECT_NAME}_HEADERS)

# list cpp files excluding platform-dependent files
list(APPEND ${CURRENT_PROJECT_NAME}_SOURCES src/main.cpp)

add_executable(${CURRENT_PROJECT_NAME}
        ${${CURRENT_PROJECT_NAME}_HEADERS}
        ${${CURRENT_PROJECT_NAME}_SOURCES})

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        EXPORT_NAME ${CURRENT_PROJECT_NAME}
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED TRUE)

target_link_libraries(${CURRENT_PROJECT_NAME}
        crypto3::pubkey
        crypto3::algebra
        crypto3::hash
        crypto3::random
        crypto3::multiprecision
        crypto3::block
        crypto3::zk
        crypto3::mac
        crypto3::math
        crypto3::modes
        crypto3::containers
        crypto3::stream
        crypto3::codec
        marshalling::core
        marshalling::crypto3_algebra
        boost_random
        )

target_include_directories(${CURRENT_PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )