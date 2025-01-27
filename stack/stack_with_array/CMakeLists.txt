
add_library(stack_lib src/my_stack.cc)

target_include_directories(stack_lib PUBLIC inc)

add_subdirectory(test)

