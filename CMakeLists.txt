cmake_minimum_required(VERSION 3.30)

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
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

add_executable(minesweeper src/field.cpp src/game.cpp src/main.cpp)
