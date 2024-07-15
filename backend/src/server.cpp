#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <zmq.hpp>
#include "bouncingBallsMessages.pb.h"
using namespace std;

// Does zmq initialization
zmq::socket_t* createZmqSocket() {
    try {
        zmq::context_t* ctx = new zmq::context_t(1);

        std::cout<<"Socket create..."<<endl;
        zmq::socket_t* socket = new zmq::socket_t(*ctx, zmq::socket_type::rep);       
                
        std::cout<<"Socket bind..."<<endl;
        socket->bind("tcp://127.0.0.1:5555");
        std::cout<<"Socket return..."<<endl;
        return socket;
    } catch (const zmq::error_t error) {
        std::cout<<"Caught zmq exception when binding socket: " << error.what() <<endl;
        return nullptr;
    } catch (const std::exception e) {
        std::cout<<"Caught standard exception when binding socket: " << e.what() <<endl;
        return nullptr;
    } catch (...) {
        std::cout<<"Caught unknown error when binding socket!"<<endl;
        return nullptr;
    }
}

// Creates a random initial state for testing
ballProto::stateUpdate initializeBallState() {
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
    std::cout<<"Finished."<<endl;
    return initialState;
}

ballProto::stateUpdate calculateNextStateUpdate(ballProto::stateUpdate* previousUpdate){
    std::cout<< "Not implemented yet!" << std::endl;
    return *previousUpdate;
}

ballProto::stateUpdate constructStateUpdateFromReceivedMsg(zmq::message_t* receivedMessage) {
    ballProto::stateUpdate stateUpdate;
    stateUpdate.ParseFromString(receivedMessage->to_string());
    return stateUpdate;
}

int main() {
    std::cout<<"Verifying protobuf version..."<<endl;
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::cout<<"Protobuf version OK!"<<endl;

    ballProto::stateUpdate initialState = initializeBallState();    
    std::cout<<"Here is the initial state: "<<endl;
    std::cout<<initialState.DebugString()<<endl;

    std::cout<<"Creating server socket..."<<endl;
    zmq::socket_t* serverSocket = createZmqSocket();  
    std::cout<<"Server socket created!"<<endl;

    // Start listening for messages
    std::cout<<"Beginning to listen for updates."<<endl;
    while (true) {
        zmq::message_t receivedMessage;
        serverSocket->recv(receivedMessage, zmq::recv_flags::none);
        std::cout<< "Received message: " << receivedMessage.to_string() << std::endl;

        // Convert message to ballProto::stateUpdate
        ballProto::stateUpdate receivedStateUpdate = constructStateUpdateFromReceivedMsg(&receivedMessage);
        std::cout<< "Constructed stateUpdate: " << receivedStateUpdate.DebugString() << std::endl;

        std::cout<<"Calculating next state update..."<<endl;
        ballProto::stateUpdate nextStateUpdate = calculateNextStateUpdate(&receivedStateUpdate);
        std::cout<<"Next state calculated!"<<endl;

        std::cout<<"Sending next state update to client..."<<endl;
        serverSocket->send(zmq::buffer(nextStateUpdate.SerializeAsString()), zmq::send_flags::none);
        std::cout<<"Next state update sent!"<<endl;
    }

    return 0;
}