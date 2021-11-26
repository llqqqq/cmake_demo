
add_executable(taskvent taskvent.cpp)
target_link_libraries(taskvent libzmq)

add_executable(taskwork taskwork.cpp)
target_link_libraries(taskwork libzmq)

add_executable(tasksink tasksink.cpp)
target_link_libraries(tasksink libzmq)