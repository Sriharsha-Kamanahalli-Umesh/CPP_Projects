cmake_minimum_required(VERSION 3.16)

add_library(myexception my_exception.cc)

target_include_directories(myexception PUBLIC my_exception.h)

add_executable(myexception  main_test.cc)
target_link_libraries(main 
  PUBLIC
    myvector
    GTest::GTest
    GTest::Main)

add_test(NAME MyLibraryTest COMMAND main)
