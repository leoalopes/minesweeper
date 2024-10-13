cmake_minimum_required(VERSION 3.24)

file(GLOB CORE_FILES "src/*.cpp")
add_library(core SHARED ${CORE_FILES})

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(test)
