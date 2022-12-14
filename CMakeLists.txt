cmake_minimum_required(VERSION 3.24)
project(XNum)

set(CMAKE_CXX_STANDARD 20)

add_library(XNum src/Number.cpp include/Number.hpp src/StringUtils.cpp include/StringUtils.hpp src/Random.cpp include/Random.hpp)
target_include_directories(XNum PRIVATE include)
target_precompile_headers(XNum PRIVATE include/xnumpch.hpp)

# Set up app
add_executable(App app/main.cpp)
target_include_directories(App PRIVATE include)
target_precompile_headers(App REUSE_FROM XNum)
target_link_libraries(App PRIVATE XNum)

# Set up Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# String Utils tests
add_executable(StringUtilsTests tests/StringUtilsTests.cpp)
target_include_directories(StringUtilsTests PRIVATE include)
target_link_libraries(StringUtilsTests PRIVATE GTest::gtest_main PRIVATE XNum)

# XNum::Number tests
add_executable(XNumberTests tests/XNumberTests.cpp)
target_include_directories(XNumberTests PRIVATE include)
target_link_libraries(XNumberTests PRIVATE GTest::gtest_main PRIVATE XNum)

include(GoogleTest)
gtest_discover_tests(StringUtilsTests)
gtest_discover_tests(XNumberTests)
