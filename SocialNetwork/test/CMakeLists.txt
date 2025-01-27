
add_executable(social_network_test  test_social_network.cc)

target_link_libraries(social_network_test 
  PUBLIC
    social_network)

