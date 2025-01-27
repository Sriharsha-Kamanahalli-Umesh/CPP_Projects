
add_library(stack_with_list_lib src/stack_with_list.cc)

target_include_directories(stack_with_list_lib PUBLIC inc)

add_subdirectory(test)
