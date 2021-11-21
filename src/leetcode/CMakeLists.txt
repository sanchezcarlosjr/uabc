cmake_minimum_required(VERSION 3.10)
project(roman-to-decimal)

set(CMAKE_CXX_STANDARD 17)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(roman-to-decimal tests.cpp roman-to-decimal.cpp)
target_link_libraries(roman-to-decimal ${GTEST_LIBRARIES} pthread)
