# cmake_minimum_required(VERSION 3.16)

# project(Thread_project CXX)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)

add_executable(future_and_promise
    future_and_promise.cc
    )
target_link_libraries(future_and_promise ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_function
    thread_with_function.cc
    )
    target_link_libraries(thread_with_function ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_functors 
    thread_with_functors.cc
    )
target_link_libraries(thread_with_functors ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_join
    thread_with_join.cc
    )
target_link_libraries(thread_with_join ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_joinable
    thread_with_joinable.cc
    )
target_link_libraries(thread_with_joinable ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_lambda
    thread_with_lambda.cc
    )
target_link_libraries(thread_with_lambda ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_with_racecond
    thread_with_racecond.cc
    )
target_link_libraries(thread_with_racecond ${CMAKE_THREAD_LIBS_INIT})

add_executable(atomic_var
    atomic_variable.cc
    )
target_link_libraries(atomic_var ${CMAKE_THREAD_LIBS_INIT})


add_executable(condition_var
    condition_variable.cc
    )
target_link_libraries(condition_var ${CMAKE_THREAD_LIBS_INIT})

add_executable(prod_cons
    prod_cons.cc
    )
target_link_libraries(prod_cons ${CMAKE_THREAD_LIBS_INIT})