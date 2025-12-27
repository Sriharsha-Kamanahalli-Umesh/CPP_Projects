
add_library(stack_with_list_lib src/stack_with_list.cc)

target_include_directories(stack_with_list_lib PUBLIC inc)

set_target_properties(stack_with_list_lib PROPERTIES
    CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*;-warnings-as-errors=modernize-use-default-member-init,modernize-loop-convert,modernize-use-equals-default"
)

add_subdirectory(test)
