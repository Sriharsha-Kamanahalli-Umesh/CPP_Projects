cmake_minimum_required(VERSION 3.16)
project(myproject)

find_package(Threads)
find_package(GTest REQUIRED)

include(cmake/gcovr.cmake)

# Enable code coverage flags if using GCC or Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Enabling code coverage compilation flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

add_subdirectory(gtest)
add_subdirectory(exception)
add_subdirectory(polymorphism)
add_subdirectory(queue)
add_subdirectory(SocialNetwork)
add_subdirectory(SocketProgram)
add_subdirectory(Sort)
add_subdirectory(stack)
add_subdirectory(templates)
add_subdirectory(advance_cpp)

