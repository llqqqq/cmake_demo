add_executable(test_uv main.cpp)
#target_link_libraries(test_uv libuv)
target_link_libraries(test_uv libuv-static)