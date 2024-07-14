cmake_minimum_required(VERSION 3.10)

project(BouncingBalls)
add_executable(BouncingBalls server.cpp)

add_subdirectory("external/zeromq")

target_link_libraries(BouncingBalls cppzmq)