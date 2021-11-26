# zero mq 示例

## zmq 构建

cmake 构建,在构建目录下执行`cmake --install ./`，记得设置 `CMAKE_INSTALL_PREFIX`

## 使用 add_library 导入 zmq 依赖

创建 `deps` 文件夹,`bin` 下放 .dll，include 下头文件，lib 下 .lib

静态库这样加载有问题

## 使用 find_package 导入 zmq 依赖

在 CmakeLists.txt 添加

```
#set(ZeroMQ_DIR   "zmq_install/CMake")
set(ZeroMQ_DIR   "zmq_build_dir")
find_package(ZeroMQ REQUIRED)
include_directories(${ZeroMQ_INCLUDE_DIR})
```

install 这个目录只有'Release'，执行 `cmake --install ./ --config Debug` 会覆盖 dll 文件，
直接 `set(ZeroMQ_DIR   "zmq_build_dir")`，`zmq_build_dir` 指向 cmake 的 build 目录

链接
```
target_link_libraries(server libzmq)
target_link_libraries(client libzmq-static)
```

其他定义看 `ZeroMQConfig.cmake`

## 链接静态库时 RuntimeLibrary 不匹配问题

静态链接时编译 server 的 debug 版本会报错

```
1>libzmq-v142-mt-s-4_3_3.lib(mechanism_base.obj) : error LNK2038: 检测到“_ITERATOR_DEBUG_LEVEL”的不匹配项: 值“0”不匹配值“2”(server.obj 中)
1>libzmq-v142-mt-s-4_3_3.lib(mechanism_base.obj) : error LNK2038: 检测到“RuntimeLibrary”的不匹配项: 值“MD_DynamicRelease”不匹配值“MDd_DynamicDebug”(server.obj 中)
```

代码的问题，使用 client.c 的代码没问题。。。

测试 server 加入 `#include <thread>` `#include <chrono>` 就会报这样的错误，注释掉就可以编译，很明显是多线程引入的问题

解决：
set(ZeroMQ_DIR   "zmq_build_dir")

