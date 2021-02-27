cmake_minimum_required(VERSION 3.10)
project(helloworld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-D_GLIBCXX_USE_CXX17_ABI=0")

add_executable(helloworld main.cpp Student.cpp Degree.cpp)

target_link_libraries(helloworld)