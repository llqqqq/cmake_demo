cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_libevent VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## import libevent

# 同时导入动态库、静态库需要参考 LibeventConfig.cmake 自行导入
set(Libevent_DIR "D:/source_code/libevent/libevent-vs2019")
set(LIBEVENT_STATIC_LINK true)
find_package(Libevent REQUIRED COMPONENTS core)

add_subdirectory(src)

message("\n\n=======================================")
message("LIBEVENT_FOUND:        " ${LIBEVENT_FOUND})
message("LIBEVENT_VERSION:      " ${LIBEVENT_VERSION})
message("LIBEVENT_INCLUDE_DIRS: " ${LIBEVENT_INCLUDE_DIRS})
message("LIBEVENT_INCLUDE_DIR:  " ${LIBEVENT_INCLUDE_DIR})
message("LIBEVENT_LIBRARIES:    " ${LIBEVENT_LIBRARIES})
message("LIBEVENT_LIBRARY:      " ${LIBEVENT_LIBRARY})
message("=======================================\n\n")