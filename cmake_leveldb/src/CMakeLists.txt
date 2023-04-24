add_executable(test_leveldb main.cpp)

target_link_libraries(test_leveldb leveldb::leveldb Threads::Threads)