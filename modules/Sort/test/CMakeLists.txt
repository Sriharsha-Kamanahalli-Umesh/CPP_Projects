
add_executable(sort_test test_sort.cc)

target_link_libraries(sort_test 
  PUBLIC
    sort_lib
    GTest::GTest
    GTest::Main)

