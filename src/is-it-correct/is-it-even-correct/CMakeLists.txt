# CMake configuration for the two-file Is It Correct demo.
cmake_minimum_required(VERSION 3.15)

project(is_it_even_correct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(is_it_even_correct main.cpp is_passing.cpp)
target_compile_options(is_it_even_correct PRIVATE -Wall -Wextra)
