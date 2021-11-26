# 如何完整引入 cmake 的依赖

主要参考了 zeromq 编译后生成的 `ZeroMQTargets.cmake` 文件，对 Release、Debug 引入不同的配置，参考如下：

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