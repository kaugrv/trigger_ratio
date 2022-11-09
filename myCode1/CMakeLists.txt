cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(simpleProject)

# file to compile and name of the executable
add_executable(simpleProject src/main.cpp src/plop.cpp include/plop.hpp)

# include directory
target_include_directories(simpleProject PRIVATE "include")

# compilation options
target_compile_features(simpleProject PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(simpleProject PRIVATE /W3)
else()
    target_compile_options(simpleProject PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

