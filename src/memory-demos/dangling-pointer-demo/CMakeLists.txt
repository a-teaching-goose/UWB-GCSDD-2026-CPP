# CMake configuration for the dangling-pointer memory demo.
cmake_minimum_required(VERSION 3.15)

project(dangling_pointer_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dangling_pointer dangling_pointer.cpp)
target_compile_options(dangling_pointer PRIVATE -Wall -Wextra)
