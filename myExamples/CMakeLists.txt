cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(examplesRatio)

# file to compile and name of the executable
add_executable(examplesRatio src/main.cpp src/plop.cpp include/plop.hpp)

# include directory
target_include_directories(examplesRatio PRIVATE "include")

# compilation options
target_compile_features(examplesRatio PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(examplesRatio PRIVATE /W3)
else()
    target_compile_options(examplesRatio PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

