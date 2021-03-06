################################################################################
# Minimum required build for cmake 
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#Project Name
project(GTESTTravis)

#included libraries
include(gtest.cmake)

#Prerequisites
set(CMAKE_CXX_FLAGS)
SET(COVERAGE OFF CACHE BOOL "Coverage")

#This variables are for setting the minimum and maximun requires for unitTesting
set(UNITTESTING_VERSION_MAJOR 1)
set(UNITTESTING_VERSION_MINOR 0)
set(LEARN_CMAKE_VERSION_PATCH 0)

#sets cmake to debug build
set(CMAKE_BUILD_TYPE Debug)

#Debug mode
enable_testing()

SET(TARGET_SRC ./main.cpp)

#creates an executable which can be used to run in travis
add_executable(TravisTest ${TARGET_SRC})

find_package (Threads)

target_link_libraries(TravisTest gtest ${CMAKE_THREAD_LIBS_INIT})
