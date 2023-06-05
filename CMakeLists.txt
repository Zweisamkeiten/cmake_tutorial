# Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)

# Create a project named Tutorial
project(Tutorial)

# Set the variable CMAKE_CXX_STANDARD 11
# Set the variable CMAKE_CXX_STANDARD_REQUIRED True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add an executable call Tutorial to the project
add_executable(Tutorial tutorial.cxx)
