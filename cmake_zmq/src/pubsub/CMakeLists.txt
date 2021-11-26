
add_executable(publisher publisher.cpp)
target_link_libraries(publisher libzmq)

add_executable(subscribe subscribe.cpp)
target_link_libraries(subscribe libzmq)
#target_link_libraries(server libzmq-static)