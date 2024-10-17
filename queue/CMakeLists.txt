
add_library(queue_lib queue.cc)

target_include_directories(queue_lib PUBLIC queue.h)

add_executable(queue_test  queue_main.cc)
target_link_libraries(queue_test 
  PUBLIC
    queue_lib
    GTest::GTest
    GTest::Main)

# add_test(NAME MyLibraryTest COMMAND poly_test)
