cmake_minimum_required(VERSION 3.10)
project(spike)

set(CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(spike main.cpp KArAge.cpp)