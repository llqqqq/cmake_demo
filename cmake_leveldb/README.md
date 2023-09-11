leveldb

leveldb 编译

```
cmake -S ./leveldb-1.23 -B ./build -DLEVELDB_BUILD_BENCHMARKS=OFF -DLEVELDB_BUILD_TESTS=OFF
cmake --build ./build  --config Release
cmake --install ./build  --config Release --prefix install-release

cmake --build ./build  --config Debug
cmake --install ./build  --config Debug --prefix install-debug
```

旧版 cmake 不支持 `camke --install`，需要
```
cmake -S ./leveldb-1.23 -B ./build -DCMAKE_INSTALL_PREFIX=XXXX -DLEVELDB_BUILD_BENCHMARKS=OFF -DLEVELDB_BUILD_TESTS=OFF
cmake --build ./build  --config Release
cd build & make & make install
```

在 linux 下生成 make 文件只支持一种 CMAKE_BUILD_TYPE，需要在生成时 
```
cmake -S ./leveldb-1.23 -B ./build -DCMAKE_INSTALL_PREFIX=XXXX -DLEVELDB_BUILD_BENCHMARKS=OFF -DLEVELDB_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release
```

**linux/mac 下还是编译不过**

mac  linux 下编译的时候，由于 level db 使用了 `-f--fno-rtti` 选项，会导致没有办法继承 leveldb 的数据结构, 可以注释掉这里的设置

leveldb 的 cmake 文件：
```
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # Disable C++ exceptions.
  string(REGEX REPLACE "/EH[a-z]+" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHs-c-")
  add_definitions(-D_HAS_EXCEPTIONS=0)

  # Disable RTTI.
  string(REGEX REPLACE "/GR" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GR-")
else(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # Enable strict prototype warnings for C code in clang and gcc.
  if(NOT CMAKE_C_FLAGS MATCHES "-Wstrict-prototypes")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wstrict-prototypes")
  endif(NOT CMAKE_C_FLAGS MATCHES "-Wstrict-prototypes")

  # Disable C++ exceptions.
  string(REGEX REPLACE "-fexceptions" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

  # Disable RTTI.
  string(REGEX REPLACE "-frtti" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
```

https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/C_002b_002b-Dialect-Options.html

> -fno-rtti 
> Disable generation of information about every class with virtual functions for use by the C++ run-time type identification features (dynamic_cast and typeid). 
> If you don’t use those parts of the language, you can save some space by using this flag. 
> Note that exception handling uses the same information, but G++ generates it as needed. 
> The dynamic_cast operator can still be used for casts that do not require run-time type information, 
> i.e. casts to void * or to unambiguous base classes. 
>
> Mixing code compiled with -frtti with that compiled with -fno-rtti may not work. 
> For example, programs may fail to link if a class compiled with -fno-rtti is used as a base for a class compiled with -frtti.

### CMake 版本问题

在源码模式之下，由于低版本的 cmake 使用 `option()` 声明开关的时候，回丢弃掉已经设置的参数，所以需要 3.13 以上的版本