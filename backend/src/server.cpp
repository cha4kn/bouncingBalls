#include <time.h>
#include <random>
#include <fstream>
#include <zmq.hpp>
#include "bouncingBallsMessages.pb.h"
#include <balls.h>
#include <spdlog/spdlog.h>
#include <json/json.h>

using namespace std;

string config_file_name = "../backend_config.json";
string port_conf_string;
string log_level_conf_string;

void readConfigFile() {
    ifstream file_stream(config_file_name, ifstream::binary);
    Json::Reader jsonReader;
    Json::Value json_config;
    Json::FastWriter jsonWriter;

    file_stream >> json_config;
    port_conf_string = json_config["port"].asString();
    log_level_conf_string = json_config["logLevel"].asString();

    cout << "-------------------------------------" << endl;
    cout << "Found config variables: " << endl;
    cout << "Port: " << port_conf_string << endl;
    cout << "Log Level: " << log_level_conf_string << endl;
    cout << "-------------------------------------" << endl;
}

// Sets up the log level depending on what was set in the config file
void setupLogger() {
    cout << "Setting up logger..." << endl;
    if (log_level_conf_string.compare("trace") == 0) {
        cout << "Setting log level trace." << endl;
        spdlog::set_level(spdlog::level::trace);
    } else if (log_level_conf_string.compare("info") == 0) {
        cout << "Setting log level info." << endl;
        spdlog::set_level(spdlog::level::info);
    } else if (log_level_conf_string.compare("debug") == 0) {
        cout << "Setting log level debug." << endl;
        spdlog::set_level(spdlog::level::debug);
    } else if (log_level_conf_string.compare("warn") == 0) {
        cout << "Setting log level warn." << endl;
        spdlog::set_level(spdlog::level::warn);
    } else if (log_level_conf_string.compare("error") == 0) {
        cout << "Setting log level error." << endl;
        spdlog::set_level(spdlog::level::err);
    } else if (log_level_conf_string.compare("critical") == 0) {
        cout << "Setting log level critical." << endl;
        spdlog::set_level(spdlog::level::critical);
    } else {
        cout << "No fitting spdlog::level matches given config string: " << log_level_conf_string << endl;
        cout << "Exiting program..." << endl;
        exit(1);
    }
    cout << "Logger setup." << endl;
    cout << "-------------------------------------" << endl;
}

// Does zmq initialization
zmq::socket_t* createZmqSocket() {
    try {
        zmq::context_t* ctx = new zmq::context_t(1);

        spdlog::debug("Creating socket...");
        zmq::socket_t* socket = new zmq::socket_t(*ctx, zmq::socket_type::rep);       

        spdlog::debug("Binding socket...");
        socket->bind("tcp://127.0.0.1:" + port_conf_string);
        
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
    
    State state = State(previousUpdate->xmax(), previousUpdate->ymax());
    for (int i = 0; i < size; i++) {
        ballProto::Ball tmpBall = previousUpdate->balls(i);
        state.addBall(Ball(tmpBall.x(), tmpBall.y(), tmpBall.vx(), tmpBall.vy(), tmpBall.r()));
    }
    
    handleCompleteState(state);

    ballProto::stateUpdate newState;
    std::vector<Ball> ballArray = state.getBalls();
    for (int i = 0; i < size; i++) {
        ballProto::Ball* tmpBall = newState.add_balls();
        tmpBall->set_x(ballArray[i].getX());
        tmpBall->set_y(ballArray[i].getY());
        tmpBall->set_vx(ballArray[i].getVx());
        tmpBall->set_vy(ballArray[i].getVy());
        tmpBall->set_r(ballArray[i].getR());
    }

    newState.set_ballcount(size);
    newState.set_xmax(previousUpdate->xmax());
    newState.set_ymax(previousUpdate->ymax());

    spdlog::debug("New state is: " + newState.DebugString());

    return newState;
}

ballProto::stateUpdate constructStateUpdateFromReceivedMsg(zmq::message_t* receivedMessage) {
    ballProto::stateUpdate stateUpdate;
    stateUpdate.ParseFromString(receivedMessage->to_string());
    return stateUpdate;
}

int main() {
    readConfigFile();
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