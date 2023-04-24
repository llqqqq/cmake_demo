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