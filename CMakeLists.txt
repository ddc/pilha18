cmake_minimum_required(VERSION 3.13)  # CMake version check
project(pilha18)                      # Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp matriz.cpp pilha.cpp utils.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(pilha18 ${SOURCE_FILES})