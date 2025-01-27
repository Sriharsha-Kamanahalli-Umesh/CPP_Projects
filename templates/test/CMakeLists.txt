
add_executable(template_test test_my_vector.cc)

target_link_libraries(template_test 
  PUBLIC
    myvector
    GTest::GTest
    GTest::Main)

