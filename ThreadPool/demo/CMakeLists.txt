cmake_minimum_required(VERSION 3.0)

project(example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
add_compile_options(-Wno-unused-variable)

include_directories(../include)
find_package(Threads REQUIRED)

add_executable(demo multi_thread_demo.cpp)
target_link_libraries(demo PRIVATE Threads::Threads)

add_executable(demo1 multi_thread_demo_1.cpp)
target_link_libraries(demo1 PRIVATE Threads::Threads)
