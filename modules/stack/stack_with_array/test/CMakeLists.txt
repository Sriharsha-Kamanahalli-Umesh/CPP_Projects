
add_executable(stack_with_array_test  test_stack_with_array.cc)

target_link_libraries(stack_with_array_test 
  PUBLIC
    stack_lib
    GTest::GTest
    GTest::Main)

