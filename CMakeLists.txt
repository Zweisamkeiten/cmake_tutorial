# Set the minimum required version of CMake to be 3.10
cmake_minimum_required(VERSION 3.15)

# Create a project named Tutorial Set the project version number as 1.0
project(Tutorial VERSION 1.0)

# Setting the C++ Standard with Interface Libraries
add_library(tutorial_compiler_flags INTERFACE) # 创建界面库 tutorial_compiler_flags
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when build this project via the
# BUILD_INTERFACE genex
set(gcc_lik_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(
  tutorial_compiler_flags
  INTERFACE
    "$<${gcc_lik_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

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

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)
