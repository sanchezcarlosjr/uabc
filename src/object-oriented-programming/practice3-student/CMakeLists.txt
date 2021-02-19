cmake_minimum_required(VERSION 3.10)
project(helloworld)

set(CMAKE_CXX_STANDARD 17 )
set (CMAKE_CXX_FLAGS "-D_GLIBCXX_USE_CXX17_ABI=0")
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(helloworld tests.cpp student.cpp)
target_link_libraries(helloworld ${GTEST_LIBRARIES} pthread)
