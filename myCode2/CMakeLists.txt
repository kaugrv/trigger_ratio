cmake_minimum_required(VERSION 3.13)


# give a name to the project
project(stabilisation LANGUAGES C CXX)

# set the modules dir to help cmake to find unknowed libs
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/modules/")

# find opencv
message(STATUS "look for lib opencv ..." )
find_package(OpenCV REQUIRED)
if(${OpenCV_FOUND})
	message(STATUS "lib opencv found")
	message(STATUS "  version     : " ${OpenCV_VERSION})
	message(STATUS "  include dir : " ${OpenCV_INCLUDE_DIRS})
	message(VERBOSE "  libraries   : ")
	foreach(opencvLibs ${OpenCV_LIBS})
		message(VERBOSE "        " ${opencvLibs})
	endforeach()	

	# (optional) check opencv version
	if(${OpenCV_VERSION} VERSION_LESS 2.0.0)
		message(FATAL_ERROR “OpenCV version is not compatible : ${OpenCV_VERSION}”)
	endif()
endif()


# include Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    message(FATAL_ERROR "lib EIGEN3 not found")
endif()


# files to compile
add_executable(stabilisation src/imageStabilization.cpp)

# compilation flags
target_compile_features(stabilisation PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(stabilisation PRIVATE /W3)
else()
    target_compile_options(stabilisation PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# lib include path
target_include_directories(stabilisation PRIVATE "${OpenCV_INCLUDE_DIRS}")
target_include_directories(stabilisation PRIVATE "${EIGEN3_INCLUDE_DIR}")

# specify the library lib path
target_link_libraries(stabilisation PRIVATE ${OpenCV_LIBS})


