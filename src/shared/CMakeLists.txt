cmake_minimum_required(VERSION 3.10)
project(helloworld)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-D_GLIBCXX_USE_CXX17_ABI=0")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(helloworld DataStructure/List/ListTest.cpp)
target_link_libraries(helloworld ${GTEST_LIBRARIES} pthread)
