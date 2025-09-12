# CMake describes how to build this program on macOS and Ubuntu.
# Build with: mkdir build && cd build && cmake .. && cmake --build .

# Require a modern CMake version available on both platforms.
cmake_minimum_required(VERSION 3.15)

# Give the project a name and say it uses C++.
project(mariolab LANGUAGES CXX)

# Require portable C++17 syntax rather than compiler-specific extensions.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build an executable named mariolab from the one source file.
add_executable(mariolab main.cpp)

# These warnings work with both Apple Clang (macOS) and GCC (Ubuntu).
target_compile_options(mariolab PRIVATE -Wall -Wextra)
