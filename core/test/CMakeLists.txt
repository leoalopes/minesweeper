cmake_minimum_required(VERSION 3.24)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

include (GoogleTest)

file(GLOB TEST_FILES "core/*.test.cpp")
foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WLE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} core GTest::gtest_main)
    gtest_discover_tests(${TEST_NAME})
    set_target_properties(${TEST_NAME} PROPERTIES CXX_CLANG_TIDY "")
endforeach()

# Silence clang-tidy warnings for gtest
set_target_properties(gtest PROPERTIES CXX_CLANG_TIDY "")
set_target_properties(gtest_main PROPERTIES CXX_CLANG_TIDY "")
set_target_properties(gmock PROPERTIES CXX_CLANG_TIDY "")
set_target_properties(gmock_main PROPERTIES CXX_CLANG_TIDY "")
