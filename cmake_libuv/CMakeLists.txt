cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_libuv VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## import libuv

set (LIBUV_INSTALL_PATH "D:/source_code/libuv/libuv-install")

add_library(libuv SHARED IMPORTED)
set_target_properties(libuv PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LIBUV_INSTALL_PATH}/include"
)

add_library(libuv-static STATIC IMPORTED)
set_target_properties(libuv-static PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LIBUV_INSTALL_PATH}/include"
  INTERFACE_LINK_LIBRARIES "ws2_32;iphlpapi;Psapi;userenv"
)

# Import target "libuv" for configuration "Debug"
set_property(TARGET libuv APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libuv PROPERTIES
  IMPORTED_IMPLIB_DEBUG     "${LIBUV_INSTALL_PATH}/lib/Debug/uv.lib"
  IMPORTED_LOCATION_DEBUG   "${LIBUV_INSTALL_PATH}/lib/Debug/uv.dll"
  )

# Import target "libuv-static" for configuration "Debug"
set_property(TARGET libuv-static APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(libuv-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "C;CXX;RC"
  IMPORTED_LOCATION_DEBUG "${LIBUV_INSTALL_PATH}/lib/Debug/uv_a.lib"
  )

# Import target "libuv" for configuration "Release"
set_property(TARGET libuv APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libuv PROPERTIES
  IMPORTED_IMPLIB_RELEASE   "${LIBUV_INSTALL_PATH}/lib/Release/uv.lib"
  IMPORTED_LOCATION_RELEASE "${LIBUV_INSTALL_PATH}/lib/Release/uv.dll"
  )

# Import target "libuv-static" for configuration "Release"
set_property(TARGET libuv-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libuv-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX;RC"
  IMPORTED_LOCATION_RELEASE "${LIBUV_INSTALL_PATH}/lib/Release/uv_a.lib"
  )

add_subdirectory(src)