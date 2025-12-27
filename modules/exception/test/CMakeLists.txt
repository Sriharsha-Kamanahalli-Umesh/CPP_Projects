

add_executable(myexception_test  test_my_exception.cc)

target_link_libraries(myexception_test 
  PUBLIC
    myexception
    GTest::GTest
    GTest::Main)
