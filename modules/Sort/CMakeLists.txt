
add_library(sort_lib src/sort.cc)

target_include_directories(sort_lib PUBLIC inc)

set_target_properties(sort_lib PROPERTIES
    CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*;-warnings-as-errors=modernize-use-default-member-init,modernize-loop-convert"
)

add_subdirectory(test)

