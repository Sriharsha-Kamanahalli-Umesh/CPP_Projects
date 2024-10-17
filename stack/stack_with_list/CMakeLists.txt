
add_library(stack_with_list_lib stack_with_list.cc)

target_include_directories(stack_with_list_lib PUBLIC stack_with_list.h)

add_executable(stack_with_list_test  main_test.cc)
target_link_libraries(stack_with_list_test 
  PUBLIC
    stack_with_list_lib
    GTest::GTest
    GTest::Main)

# add_test(NAME test_stack COMMAND stack_test)
