
add_executable(stack_with_list_test  test_stack_with_list.cc)

target_link_libraries(stack_with_list_test 
  PUBLIC
    stack_with_list_lib
    GTest::GTest
    GTest::Main)
