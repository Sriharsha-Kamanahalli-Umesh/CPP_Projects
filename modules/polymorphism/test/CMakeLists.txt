
add_executable(poly_test test_runtime_poly.cc)

target_link_libraries(poly_test 
  PUBLIC
    poly_lib
    GTest::GTest
    GTest::Main)

