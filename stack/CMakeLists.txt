
add_library(stack_lib my_stack.cc)

target_include_directories(stack_lib PUBLIC my_stack.h)

add_executable(stack_test  stack_main.cc)
target_link_libraries(stack_test 
  PUBLIC
    stack_lib
    GTest::GTest
    GTest::Main)

add_subdirectory(stack_with_list)

# add_test(NAME test_stack COMMAND stack_test)
