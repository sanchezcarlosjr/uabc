cmake_minimum_required(VERSION 3.10)
project(oop-test3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(oop-test3 src/tests.cpp src/Ecosystem.cpp src/Ecosystem.h ../shared/Test/StdoutMock.cpp ../shared/RegexLib/RegexLib.cpp)
target_link_libraries(oop-test3 ${GTEST_LIBRARIES} pthread)