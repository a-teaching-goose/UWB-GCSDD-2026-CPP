# CMake configuration for the DynamicArray memory-leak lesson demo.
cmake_minimum_required(VERSION 3.15)

project(memory_leak_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(memory_leak memory_leak.cpp)
target_compile_options(memory_leak PRIVATE -Wall -Wextra)
