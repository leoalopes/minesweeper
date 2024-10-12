cmake_minimum_required(VERSION 3.24)

add_executable(minesweeper src/main.cpp src/ui/cli.cpp)
target_link_libraries(minesweeper core)
