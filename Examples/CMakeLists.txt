cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(Examples)

# file to compile and name of the executable
add_executable(Examples src/main.cpp src/plop.cpp include/plop.hpp)

#add dependencies
target_link_libraries(Examples PRIVATE libRatio)
# include directory
target_include_directories(Examples PRIVATE "include")

# compilation options
target_compile_features(Examples PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(Examples PRIVATE /W3)
else()
    target_compile_options(Examples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

