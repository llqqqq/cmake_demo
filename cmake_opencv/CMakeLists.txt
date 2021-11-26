cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_opencv VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# bin output 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# opencv
set(OpenCV_DIR   "D:/source_code/opencv/opencv-4.5.4-vs2019/install")
FIND_PACKAGE(OpenCV REQUIRED)

#FIND_PACKAGE(OpenCV REQUIRED core imgcodecs)

add_subdirectory(src)

