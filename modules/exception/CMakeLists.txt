cmake_minimum_required(VERSION 3.16)

add_library(myexception src/my_exception.cc)

target_include_directories(myexception PUBLIC inc)

add_subdirectory(test)
