# Cmake Package Config

## reference

* [CMakePackageConfigHelpers](https://cmake.org/cmake/help/v3.4/module/CMakePackageConfigHelpers.html)
* [cmake-packages](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html)
* [find-package](https://cmake.org/cmake/help/latest/command/find_package.html)
* [config-file-packages](https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#config-file-packages)


## CMakePackageConfigHelpers 配置库


CMakePackageConfigHelpers 可以用来生成配置，方便用户导入库，不必硬编码路径

https://cmake.org/cmake/help/latest/module/CMakePackageConfigHelpers.html

CMakePackageConfigHelpers 提供了两个函数：`configure_package_config_file()` 用来配置 package，`write_basic_package_version_file()` 用来配置版本号


### configure_package_config_file()

在 FooConfig 工程的 CMakeLists.txt 文件

```cmake
include(CMakePackageConfigHelpers)

configure_package_config_file(FooConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Foo
  PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/FooConfigVersion.cmake
  VERSION 1.2.3
  COMPATIBILITY SameMajorVersion )

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/FooConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/FooConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Foo )
```

**FooConfig.cmake.in** 文件的内容:

```
set(FOO_VERSION x.y.z)
...
@PACKAGE_INIT@
...
set_and_check(FOO_INCLUDE_DIR "@PACKAGE_INCLUDE_INSTALL_DIR@")
set_and_check(FOO_SYSCONFIG_DIR "@PACKAGE_SYSCONFIG_INSTALL_DIR@")

check_required_components(Foo)
```



### write_basic_package_version_file()



### install() 

最后，我还需要配置 `install()`, 这样在执行 `cmake --install` 的时候才能争取安装



## Demo

参考 `leveldb` 的 cmake

```cmake
if(LEVELDB_INSTALL)
  install(TARGETS leveldb
    EXPORT leveldbTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
  install(
    FILES
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/c.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/cache.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/comparator.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/db.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/dumpfile.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/env.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/export.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/filter_policy.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/iterator.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/options.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/slice.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/status.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/table_builder.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/table.h"
      "${LEVELDB_PUBLIC_INCLUDE_DIR}/write_batch.h"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/leveldb"
  )

  include(CMakePackageConfigHelpers)
  configure_package_config_file(
    "cmake/${PROJECT_NAME}Config.cmake.in"
    "${PROJECT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )
  write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
  )
  install(
    EXPORT leveldbTargets
    NAMESPACE leveldb::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )
  install(
    FILES
      "${PROJECT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake"
      "${PROJECT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )
endif(LEVELDB_INSTALL)
```

leveldbConfig.cmake.in:
```txt
# Copyright 2019 The LevelDB Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file. See the AUTHORS file for names of contributors.

@PACKAGE_INIT@

include("${CMAKE_CURRENT_LIST_DIR}/leveldbTargets.cmake")

check_required_components(leveldb)
```

## 使用

* https://cmake.org/cmake/help/latest/command/find_package.html#search-modes
* https://cmake.org/cmake/help/latest/command/find_package.html#search-procedure

在 **[cmake-packages](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html)** 中描述

> A config-file package is a set of files provided by upstreams for downstreams to use. CMake searches in a number of locations for package configuration files, as described in the find_package() documentation. **The most simple way for a CMake user to tell cmake(1) to search in a non-standard prefix for a package is to set the CMAKE_PREFIX_PATH cache variable**.
>
> Config-file packages are provided by upstream vendors as part of development packages, that is, they belong with the header files and any other files provided to assist downstreams in using the package.
> 
> A set of variables which provide package status information are also set automatically when using a config-file package. The <PackageName>_FOUND variable is set to true or false, depending on whether the package was found. **The <PackageName>_DIR cache variable is set to the location of the package configuration file**.

[这里](https://cmake.org/cmake/help/latest/command/find_package.html#config-mode-search-procedure)描述了 cmake 搜索 config-package 的顺序与相关的环境变量

1. New in version 3.12: 设置 `<PackageName>_ROOT` 变量，或者环境变量
2. 通过 cmake 命令行 `-DVAR=VALUE` 传入 `CMAKE_PREFIX_PATH` `CMAKE_FRAMEWORK_PATH` `CMAKE_APPBUNDLE_PATH`
3. 设置环境变量 `PackageName>_DIR` `CMAKE_PREFIX_PATH` `CMAKE_FRAMEWORK_PATH` `CMAKE_APPBUNDLE_PATH`


可以直接设置 **XXX_DIR** 路径

```
set(OpenCV_DIR   "D:/source_code/opencv/opencv-4.5.4-vs2019/install")
FIND_PACKAGE(OpenCV REQUIRED)
```