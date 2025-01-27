

add_executable(myexception_test  main_test.cc)

target_link_libraries(myexception_test 
  PUBLIC
    myexception
    GTest::GTest
    GTest::Main)


