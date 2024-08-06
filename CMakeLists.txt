cmake_minimum_required(VERSION 3.24)

project(MineSweeper VERSION 1.0 LANGUAGES CXX)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    message("CMAKE_BUILD_TYPE NOT DEFINED")
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    message("CMAKE_EXPORT_COMPILE_COMMANDS NOT DEFINED")
    set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
endif()

set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

add_library(core STATIC src/core/field.cpp src/core/game.cpp)
target_include_directories(core PUBLIC src/core)

add_executable(minesweeper src/main.cpp)
target_link_libraries(minesweeper core)
