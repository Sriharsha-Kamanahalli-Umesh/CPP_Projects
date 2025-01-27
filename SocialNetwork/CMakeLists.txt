
add_library(social_network src/social_network.cc)

target_include_directories(social_network PUBLIC inc)

add_subdirectory(test)

