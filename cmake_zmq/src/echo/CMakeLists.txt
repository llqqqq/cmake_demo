add_executable(client client.cpp)
#target_link_libraries(client libzmq)
target_link_libraries(client libzmq-static)

add_executable(server server.cpp)
#target_link_libraries(server libzmq)
target_link_libraries(server general libzmq-static)