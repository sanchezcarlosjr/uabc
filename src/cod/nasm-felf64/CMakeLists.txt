cmake_minimum_required(VERSION 3.10)

project(nasm-felf64)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_NASM_LINK_EXECUTABLE "ld   -o  ")

set(CAN_USE_ASSEMBLER TRUE)

set(CMAKE_ASM_NASM_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)

project(${project_name} ASM_NASM)

set(CMAKE_VERBOSE_MAKEFILE ON)
enable_language(ASM_NASM)

set(SOURCE_FILES calling-assembly-from-c++/maxofthree.asm practice2.asm)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(practice ${SOURCE_FILES} tests.cpp)

target_link_libraries(practice ${GTEST_LIBRARIES} pthread)