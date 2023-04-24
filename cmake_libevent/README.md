静态库一定要添加 INTERFACE_LINK_LIBRARIES

```
cmake -S ./libevent-2.1.12-stable -B ./build --install-prefix E:/source_build/libevent/install  -DEVENT__DISABLE_OPENSSL=ON
cmake --build ./build  --config Release
cmake --install ./build  --config Release --prefix install-release

cmake --build ./build  --config Debug
cmake --install ./build  --config Debug --prefix install-debug
```