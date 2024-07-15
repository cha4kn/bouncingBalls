#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <zmq.hpp>
#include "bouncingBallsMessages.pb.h"
using namespace std;

int main() {
    std::cout<<"Verifying protobuf version..."<<endl;
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::cout<<"Protobuf version OK!"<<endl;

    std::cout<<"Adding balls to initial state..."<<endl;
    ballProto::stateUpdate initialState;    
    // Add balls to the state
    for (int i = 0; i < 10; i++) {
        ballProto::Ball* ballToAdd = initialState.add_balls();
        ballToAdd->set_id(i+1);
        ballToAdd->set_r(5);
        ballToAdd->set_x(i+1);
        ballToAdd->set_y(10-i);
    }
    std::cout<<"Finished. Here is the initial state: "<<endl;
    std::cout<<initialState.DebugString()<<endl;

    std::cout<<"Testing ZeroMQ stuff..."<<endl;
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    std::cout<<"ZeroMq stuff worked!"<<endl;
    return 0;
}
