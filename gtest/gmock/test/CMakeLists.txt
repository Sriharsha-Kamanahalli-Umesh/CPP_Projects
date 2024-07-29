

add_executable(atmappliaction  test_atmapplication.cc)
target_link_libraries(atmappliaction 
  PUBLIC
    gmock_test
    GTest::GTest
    GTest::Main
    gmock)

add_test(NAME AtmTest COMMAND atmappliaction)