
add_library(sort_lib src/sort.cc)

target_include_directories(sort_lib PUBLIC inc)

add_subdirectory(test)

