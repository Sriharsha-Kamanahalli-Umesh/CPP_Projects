
add_executable(main my_vector_test.cc)
target_link_libraries(main 
  PUBLIC
    myvector
    GTest::GTest
    GTest::Main)

add_test(NAME MyLibraryTest COMMAND main)
