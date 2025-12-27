
add_library(stack_lib src/my_stack.cc)

target_include_directories(stack_lib PUBLIC inc)

set_target_properties(stack_lib PROPERTIES
    CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*;-warnings-as-errors=modernize-use-default-member-init,modernize-loop-convert"
)

add_subdirectory(test)

