# 如何完整引入 cmake 的依赖

* add_library
* add_subdirectory

## add_library

主要参考了 zeromq 编译后生成的 `ZeroMQTargets.cmake` 文件，对 Release、Debug 引入不同的配置，参考如下：

* 添加静态库要注意 INTERFACE_LINK_LIBRARIES ，没有相关设置可能会报错无法解析的外部符号

```cmake
# Create imported target libzmq
add_library(libzmq SHARED IMPORTED)

set_target_properties(libzmq PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "D:/source_code/zeromq/libzmq-4.3.3/include;D:/source_code/zeromq/libzmq-4.3.3-vs2019"
  INTERFACE_LINK_LIBRARIES "ws2_32;rpcrt4;iphlpapi"
)

# Create imported target libzmq-static
add_library(libzmq-static STATIC IMPORTED)

set_target_properties(libzmq-static PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "ZMQ_STATIC"
  INTERFACE_INCLUDE_DIRECTORIES "D:/source_code/zeromq/libzmq-4.3.3/include;D:/source_code/zeromq/libzmq-4.3.3-vs2019"
  INTERFACE_LINK_LIBRARIES "ws2_32;rpcrt4;iphlpapi"
)

# Import target "libzmq" for configuration "Debug"
set_property(TARGET libzmq APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libzmq PROPERTIES
  IMPORTED_IMPLIB_DEBUG "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/Debug/libzmq-v142-mt-gd-4_3_3.lib"
  IMPORTED_LOCATION_DEBUG "D:/source_code/zeromq/libzmq-4.3.3-vs2019/bin/Debug/libzmq-v142-mt-gd-4_3_3.dll"
  )

# Import target "libzmq-static" for configuration "Debug"
set_property(TARGET libzmq-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libzmq-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX;RC"
  IMPORTED_LOCATION_DEBUG "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/Debug/libzmq-v142-mt-sgd-4_3_3.lib"
  )

# Import target "libzmq" for configuration "Release"
set_property(TARGET libzmq APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libzmq PROPERTIES
  IMPORTED_IMPLIB_RELEASE "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/Release/libzmq-v142-mt-4_3_3.lib"
  IMPORTED_LOCATION_RELEASE "D:/source_code/zeromq/libzmq-4.3.3-vs2019/bin/Release/libzmq-v142-mt-4_3_3.dll"
  )

# Import target "libzmq-static" for configuration "Release"
set_property(TARGET libzmq-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libzmq-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;RC"
  IMPORTED_LOCATION_RELEASE "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/Release/libzmq-v142-mt-s-4_3_3.lib"
  )

# Import target "libzmq" for configuration "MinSizeRel"
set_property(TARGET libzmq APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(libzmq PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/MinSizeRel/libzmq-v142-mt-4_3_3.lib"
  IMPORTED_LOCATION_MINSIZEREL "D:/source_code/zeromq/libzmq-4.3.3-vs2019/bin/MinSizeRel/libzmq-v142-mt-4_3_3.dll"
  )

# Import target "libzmq-static" for configuration "MinSizeRel"
set_property(TARGET libzmq-static APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(libzmq-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C;CXX;RC"
  IMPORTED_LOCATION_MINSIZEREL "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/MinSizeRel/libzmq-v142-mt-s-4_3_3.lib"
  )

# Import target "libzmq" for configuration "RelWithDebInfo"
set_property(TARGET libzmq APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(libzmq PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/RelWithDebInfo/libzmq-v142-mt-4_3_3.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "D:/source_code/zeromq/libzmq-4.3.3-vs2019/bin/RelWithDebInfo/libzmq-v142-mt-4_3_3.dll"
  )

# Import target "libzmq-static" for configuration "RelWithDebInfo"
set_property(TARGET libzmq-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(libzmq-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "C;CXX;RC"
  IMPORTED_LOCATION_RELWITHDEBINFO "D:/source_code/zeromq/libzmq-4.3.3-vs2019/lib/RelWithDebInfo/libzmq-v142-mt-s-4_3_3.lib"
  )
```

## add_subdirectory

可以源码依赖，使用 git 的 submodule（创建 .gitmodules）,如
```
[submodule "third_party/googletest"]
	path = third_party/googletest
	url = https://github.com/google/googletest.git
[submodule "third_party/benchmark"]
	path = third_party/benchmark
	url = https://github.com/google/benchmark
```

使用这种方式需要在 add_subdirectory 前设置各种参数，可以参考 leveldb 使用 Googletest 和 google benchmark :

```
# Prevent overriding the parent project's compiler/linker settings on Windows.
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  set(install_gtest OFF)
  set(install_gmock OFF)
  set(build_gmock ON)

  # This project is tested using GoogleTest.
  add_subdirectory("third_party/googletest")

  # This project uses Google benchmark for benchmarking.
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_EXCEPTIONS OFF CACHE BOOL "" FORCE)
  add_subdirectory("third_party/benchmark")

  # GoogleTest triggers a missing field initializers warning.
  if(LEVELDB_HAVE_NO_MISSING_FIELD_INITIALIZERS)
    set_property(TARGET gtest
        APPEND PROPERTY COMPILE_OPTIONS -Wno-missing-field-initializers)
    set_property(TARGET gmock
        APPEND PROPERTY COMPILE_OPTIONS -Wno-missing-field-initializers)
  endif(LEVELDB_HAVE_NO_MISSING_FIELD_INITIALIZERS)
```

add 的文件夹必须在当前文件夹的下面，不然会报错：
```
  add_subdirectory not given a binary directory but the given source
  directory "D:/source_code/leveldb" is not a subdirectory of
  "D:/workspace/cmake_demo/cmake_leveldb".  When specifying an out-of-tree
  source a binary directory must be explicitly specified.
```