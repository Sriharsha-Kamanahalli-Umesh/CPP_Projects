cmake_minimum_required(VERSION 3.16)
project(myproject)

find_package(Threads)
find_package(GTest REQUIRED)

add_subdirectory(gtest)
add_subdirectory(exception)
add_subdirectory(polymorphism)
add_subdirectory(queue)
add_subdirectory(SocialNetwork)
add_subdirectory(Sort)
add_subdirectory(stack)
add_subdirectory(templates)
add_subdirectory(advance_cpp)

