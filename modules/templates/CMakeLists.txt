cmake_minimum_required(VERSION 3.16)
project(myvector)
add_library(myvector STATIC src/my_vector.cc)

enable_testing()
 #If we create INTERFACE, then it will not link with our target, 
 #here it will not link with myvector library
# target_include_directories(myvector INTERFACE inc/)
# add_library(vector_dummy STATIC src/my_vector.cc)

# #create with PRIVATE and linked with other target
# target_include_directories(myvector PRIVATE inc/) 
# add_library(vector_dummy STATIC src/my_vector.cc)

# #create with PUBLIC and linked with other target
target_include_directories(myvector PUBLIC inc/) 
# add_library(vector_dummy STATIC src/my_vector.cc)

# target_link_libraries(vector_dummy PRIVATE myvector)
# add_executable(main my_vector_test.cc)
# target_link_libraries(main 
#   PUBLIC
#     myvector
#     GTest::GTest
#     GTest::Main)

# add_test(NAME MyLibraryTest COMMAND main)


set_target_properties(myvector PROPERTIES
    CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*;-warnings-as-errors=modernize-use-default-member-init,modernize-loop-convert"
)
find_package(GTest REQUIRED)
add_subdirectory(test)
