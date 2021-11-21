cmake_minimum_required(VERSION 3.10)
project(thread1)

set(CMAKE_CXX_STANDARD 17)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(thread1 tests.cpp)
target_link_libraries(thread1 ${GTEST_LIBRARIES} pthread)
