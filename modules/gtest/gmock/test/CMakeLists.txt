

add_executable(atmappliaction  test_atmapplication.cc)
target_link_libraries(atmappliaction 
  PUBLIC
    gmock_test
    GTest::GTest
    GTest::gmock
    GTest::Main)

add_test(NAME AtmTest COMMAND atmappliaction)