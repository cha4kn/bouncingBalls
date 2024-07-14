#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <stdio.h>
using namespace std;
#include <zmq.hpp>

int main() {
    std::cout<<"Hello!"<<endl;
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    std::cout<<"ZeroMq stuff worked!"<<endl;
    return 0;
}
