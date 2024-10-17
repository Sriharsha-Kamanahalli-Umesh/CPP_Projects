
add_library(sort_lib sort.cc)

target_include_directories(sort_lib PUBLIC sort.h)

add_executable(sort_test test_sort.cc)
target_link_libraries(sort_test 
  PUBLIC
    sort_lib
    GTest::GTest
    GTest::Main)

add_test(NAME test_sort COMMAND sort_test)
