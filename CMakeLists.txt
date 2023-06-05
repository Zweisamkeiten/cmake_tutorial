# Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.10)

# Create a project named Tutorial Set the project version number as 1.0
project(Tutorial VERSION 1.0)

# Set the variable CMAKE_CXX_STANDARD 11 Set the variable
# CMAKE_CXX_STANDARD_REQUIRED True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Setting the C++ Standard with Interface Libraries
add_library(tutorial_compiler_flags INTERFACE) # 创建界面库 tutorial_compiler_flags
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# Use configure_file to configure and copy TutorialConfig.h.in to
# TutorialConfig.h
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the MathFunctions library
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()

# Add an executable call Tutorial to the project
add_executable(Tutorial tutorial.cxx)

# link library
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS} tutorial_compiler_flags)

# Use target_include_directories to include ${PROJECT_BINARY_DIR}
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
