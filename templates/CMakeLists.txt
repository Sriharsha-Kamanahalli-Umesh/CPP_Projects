cmake_minimum_required(VERSION 3.16)
# Enable code coverage flags if using GCC or Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Enabling code coverage compilation flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

find_package(Threads)
find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

add_library(myvector my_vector.cc)

enable_testing()
target_include_directories(myvector PUBLIC my_vector.h)

add_executable(main  my_vector_test.cc)
target_link_libraries(main 
  PUBLIC
    myvector
    GTest::GTest
    GTest::Main)

add_test(NAME MyLibraryTest COMMAND main)
