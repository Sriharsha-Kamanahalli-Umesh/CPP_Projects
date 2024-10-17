
add_library(poly_lib runtime_poly.cc)

target_include_directories(poly_lib PUBLIC runtime_poly.h)

add_executable(poly_test  main.cc)
target_link_libraries(poly_test 
  PUBLIC
    poly_lib
    GTest::GTest
    GTest::Main)

# add_test(NAME MyLibraryTest COMMAND poly_test)
