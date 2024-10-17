
# cmake_minimum_required(VERSION 3.16)

# project(SocailNetwork)

# find_package(Threads)

add_library(social_network src/social_network.cc)
target_include_directories(social_network PUBLIC inc)

add_executable(social_network_test  test/social_network_test.cc)
target_link_libraries(social_network_test 
  PUBLIC
    social_network)

