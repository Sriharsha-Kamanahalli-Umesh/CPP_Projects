
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

add_subdirectory(test)
