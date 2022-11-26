cmake_minimum_required(VERSION 3.13)

# project name
project(triggerRatio)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest)

# add libRatio
message(STATUS "libRatio cmake part ..." )
add_subdirectory(libRatio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRatio/include)

# add myExamples
message(STATUS "myExamples cmake part ..." )
add_subdirectory(myExamples)





