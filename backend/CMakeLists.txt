cmake_minimum_required(VERSION 3.10)

project(BouncingBalls)
set(SOURCES src/server.cpp src/balls.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../compiledProtos/cpp/bouncingBallsMessages.pb.cc)
add_executable(BouncingBalls ${SOURCES})

find_package(Protobuf REQUIRED)
target_include_directories(BouncingBalls 
    PRIVATE "${Protobuf_INCLUDE_DIR}"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../compiledProtos/cpp"
    PRIVATE "${CMAKE_CURRENT_BINARY_DIR}"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_subdirectory("external/zeromq")
add_subdirectory("external/spdlog")
add_subdirectory("external/jsoncpp")

target_link_libraries(BouncingBalls
    PRIVATE
    cppzmq
    ${PROTOBUF_LIBRARY}
    spdlog::spdlog_header_only
    jsoncpp_lib
)
