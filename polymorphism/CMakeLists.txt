
add_library(poly_lib src/runtime_poly.cc)

target_include_directories(poly_lib PUBLIC inc)

add_subdirectory(test)
