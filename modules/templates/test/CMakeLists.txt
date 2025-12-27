
add_executable(template_test test_my_vector.cc)

add_executable(main main.cpp)
target_link_libraries(main 
  PUBLIC
    myvector)
target_link_libraries(template_test 
  PUBLIC
    myvector
    GTest::GTest
    GTest::Main)

