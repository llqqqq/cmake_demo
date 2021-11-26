cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_zmq VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#include_directories(${CMAKE_SOURCE_DIR}/deps/include)

#add_library(libzmq SHARED IMPORTED)
#add_library(libzmq-static STATIC IMPORTED)  # 静态库编译错误
#set_target_properties(libzmq PROPERTIES 
#    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/deps/bin/libzmq-v142-mt-4_3_3.dll
#    IMPORTED_IMPLIB ${CMAKE_SOURCE_DIR}/deps/lib/libzmq-v142-mt-4_3_3.lib
#    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/deps/include"
#)


# use cmake package
set(ZeroMQ_DIR   "D:/source_code/zeromq/libzmq-4.3.3-vs2019/")
find_package(ZeroMQ REQUIRED)
include_directories(${ZeroMQ_INCLUDE_DIR})

add_subdirectory(src)

message("\n\n=======================================")
message("ZeroMQ_FOUND:          " ${ZeroMQ_FOUND})
message("ZeroMQ_INCLUDE_DIR:    " ${ZeroMQ_INCLUDE_DIR})
message("ZeroMQ_LIBRARY:        " ${ZeroMQ_LIBRARY})
message("ZeroMQ_STATIC_LIBRARY: " ${ZeroMQ_STATIC_LIBRARY})
message("=======================================\n\n")