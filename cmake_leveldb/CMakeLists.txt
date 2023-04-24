cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_leveldb VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# set(LEVELDB_BUILD_PATH "D:/source_code/leveldb/leveldb-vs2019")
# set(LEVELDB_SRC_PATH "D:/source_code/leveldb/leveldb-1.23")

# add_library(leveldb STATIC IMPORTED)
# set_target_properties(leveldb PROPERTIES
    # IMPORTED_LOCATION_RELEASE     "${LEVELDB_BUILD_PATH}/Release/leveldb.lib"
    # IMPORTED_LOCATION_DEBUG       "${LEVELDB_BUILD_PATH}/Debug/leveldb.lib"
    # INTERFACE_INCLUDE_DIRECTORIES "${LEVELDB_SRC_PATH}/include"
# )

# leveldb cmake 的 package 文件在安装后的 lib/cmake 下，debug 和 release 文件的名称没有区分

# 直接放源码，方便学习
#set(LEVELDB_BUILD_TESTS OFF)
#set(LEVELDB_BUILD_BENCHMARKS OFF)
#set(LEVELDB_INSTALL OFF)
#add_subdirectory(third_party/leveldb)

# 使用 Config 模式导入，此时需要连接到 leveldb::leveldb

set(leveldb_DIR "E:/source_build/leveldb/install-release/lib/cmake/leveldb/")
find_package(Threads REQUIRED) # level 的 Interface 依赖
find_package(leveldb REQUIRED)

add_subdirectory(src)