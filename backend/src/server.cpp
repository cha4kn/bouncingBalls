#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <zmq.hpp>
#include "bouncingBallsMessages.pb.h"
#include <balls.h>
#include <spdlog/spdlog.h>
#include <json/json.h>

using namespace std;

void setupLogger() {
    spdlog::set_level(spdlog::level::info);
}

// Does zmq initialization
zmq::socket_t* createZmqSocket() {
    try {
        zmq::context_t* ctx = new zmq::context_t(1);

        spdlog::debug("Creating socket...");
        zmq::socket_t* socket = new zmq::socket_t(*ctx, zmq::socket_type::rep);       

        spdlog::debug("Binding socket...");
        socket->bind("tcp://127.0.0.1:5556");
        
        return socket;
    } catch (const zmq::error_t error) {
        spdlog::error('Caught zmq exception when binding socket: ' + error.what());
        return nullptr;
    } catch (const std::exception e) {
        spdlog::error('Caught standard exception when binding socket: ' + e.what());
        return nullptr;
    } catch (...) {
        spdlog::error("Caught unknown error when binding socket!");
        return nullptr;
    }
}

// Creates a random initial state for testing
ballProto::stateUpdate initializeBallState() {
    spdlog::debug("Adding balls to initial state...");
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
    int size = previousUpdate->ballcount();
    double x_vals[size];
    double y_vals[size];
    double vx_vals[size];
    double vy_vals[size];
    double r_vals[size];
    double x_max = previousUpdate->xmax();
    double y_max = previousUpdate->ymax();
    
    for (int i = 0; i < size; i++) {
        ballProto::Ball tmpBall = previousUpdate->balls(i);
        x_vals[i] = tmpBall.x();
        y_vals[i] = tmpBall.y();
        vx_vals[i] = tmpBall.vx();
        vy_vals[i] = tmpBall.vy();
        r_vals[i] = tmpBall.r();
    }
    
    handleCompleteState(size, x_vals, y_vals, vx_vals, vy_vals, r_vals, x_max, y_max);

    ballProto::stateUpdate newState;
    for (int i = 0; i < size; i++) {
        ballProto::Ball* tmpBall = newState.add_balls();
        tmpBall->set_x(x_vals[i]);
        tmpBall->set_y(y_vals[i]);
        tmpBall->set_vx(vx_vals[i]);
        tmpBall->set_vy(vy_vals[i]);
        tmpBall->set_r(r_vals[i]);
    }

    newState.set_ballcount(size);
    newState.set_xmax(x_max);
    newState.set_ymax(y_max);

    spdlog::debug("New state is: " + newState.DebugString());

    return newState;
}

ballProto::stateUpdate constructStateUpdateFromReceivedMsg(zmq::message_t* receivedMessage) {
    ballProto::stateUpdate stateUpdate;
    stateUpdate.ParseFromString(receivedMessage->to_string());
    return stateUpdate;
}

int main() {
    setupLogger();

    spdlog::info("Verifying protobuf version...");
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    spdlog::info("Protobuf version OK!");

    spdlog::info("Creating server socket...");
    zmq::socket_t* serverSocket = createZmqSocket();  
    spdlog::info("Server socket created and bound!");

    // Start listening for messages
    spdlog::info("Beginning to listen for updates.");
    while (true) {
        zmq::message_t receivedMessage;
        serverSocket->recv(receivedMessage, zmq::recv_flags::none);
        spdlog::debug("Received a message!");

        // Convert message to ballProto::stateUpdate
        ballProto::stateUpdate receivedStateUpdate = constructStateUpdateFromReceivedMsg(&receivedMessage);
        spdlog::debug("Constructed stateUpdate from message: " + receivedStateUpdate.DebugString());
        //std::cout<< "Constructed stateUpdate: " << receivedStateUpdate.DebugString() << std::endl;

        spdlog::debug("Calculating next state update...");
        ballProto::stateUpdate nextStateUpdate = calculateNextStateUpdate(&receivedStateUpdate);
        spdlog::debug("Next state calculated!");

        spdlog::debug("Sending next state update to client...");
        serverSocket->send(zmq::buffer(nextStateUpdate.SerializeAsString()), zmq::send_flags::none);
        spdlog::debug("Next state update sent!");
    }

    return 0;
}