cmake_minimum_required(VERSION 3.16)
project(myproject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*;-warnings-as-errors=modernize-use-default-member-init")
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

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_options(-fprofile-arcs -ftest-coverage)         # add coverage instrumentation only for Linux since gcov is only used on Linux builds currently
    set(OPTIMIZATION "-O0")
    set(LINK_TIME_OPTIMIZATION "-flto")
    message("OVERRIDDEN OPTIMIZATION LEVEL:" ${OPTIMIZATION})
    add_compile_options(${OPTIMIZATION})
    message("OVERRIDDEN LINK_TIME_OPTIMIZATION" ${LINK_TIME_OPTIMIZATION})
    add_compile_options(${LINK_TIME_OPTIMIZATION})
    # Adding debug info
    add_compile_options("-g")
endif()



# Combined target
# add_custom_target(doc ALL
# DEPENDS doc_doxygen doc_sphinx) 

add_subdirectory(docs)
add_subdirectory(modules/gtest)
add_subdirectory(modules/exception)
add_subdirectory(modules/polymorphism)
add_subdirectory(modules/queue)
add_subdirectory(modules/SocialNetwork)
add_subdirectory(modules/SocketProgram)
add_subdirectory(modules/Sort)
add_subdirectory(modules/stack)
add_subdirectory(modules/templates)
add_subdirectory(modules/advance_cpp)

