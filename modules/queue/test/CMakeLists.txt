
add_executable(queue_test  test_queue.cc)

target_link_libraries(queue_test 
  PUBLIC
    queue_lib
    GTest::GTest
    GTest::Main)

# add_test(NAME MyLibraryTest COMMAND poly_test)
