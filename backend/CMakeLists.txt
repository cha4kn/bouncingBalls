cmake_minimum_required(VERSION 3.10)

set( CMAKE_C_COMPILER "C:/mysys64/ucrt64/bin/gcc.exe" )
set( CMAKE_CXX_COMPILER "C:/mysys64/ucrt64/bin/g++.exe" )

project(BouncingBalls)

add_executable(BouncingBalls server.cpp)