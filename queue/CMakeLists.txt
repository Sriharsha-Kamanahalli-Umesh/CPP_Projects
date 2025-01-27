
add_library(queue_lib src/queue.cc)

target_include_directories(queue_lib PUBLIC inc)

add_subdirectory(test)
