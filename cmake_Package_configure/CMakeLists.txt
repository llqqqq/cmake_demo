cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(libhello VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# add lib

add_library(libhello hello.h hello.c)

# 
include(include(CMakePackageConfigHelpers)
