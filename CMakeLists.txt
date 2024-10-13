cmake_minimum_required(VERSION 3.24)

project(MineSweeper VERSION 1.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_GENERATOR "Unix Makefiles")
set(CMAKE_C_COMPILER "/bin/gcc")
set(CMAKE_CXX_COMPILER "/bin/c++")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

enable_testing()

add_subdirectory(core)
add_subdirectory(app)
