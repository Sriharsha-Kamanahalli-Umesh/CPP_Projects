
cmake_minimum_required(VERSION 3.22)

project(AtmApplication)
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

add_library(gmock_test src/abankserver.cc src/atmapplication.cc)
target_include_directories(gmock_test PUBLIC inc)

enable_testing()
add_subdirectory(test)