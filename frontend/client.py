# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 13:47:13 2024

@author: afors
"""

import zmq
import time
import numpy as np
import gui
import bouncingBallsMessages_pb2 as ballProto
import random as rd
import configparser as cp

# Config file parameters
config_file_name = "config.txt"
config_comm_section_name = "COMM"
config_gui_section_name = "GUI"
config_initial_state_section_name = "INITIAL STATE"

# --------- Setup -------------------------------------------------------------
def parseConfigFile():
    global number_of_balls
    global x_max
    global y_max
    global r_max
    global v_max
    global server_ip
    global server_port
    global x_vals
    global y_vals
    global r_vals
    global max_fps

    config = cp.ConfigParser()
    config.read_file(open(config_file_name))

    # Parse config file key value pairs
    server_ip = config.get(config_comm_section_name, 'server_ip')
    server_port = config.get(config_comm_section_name, 'server_port')
    x_max = int(config.get(config_gui_section_name, 'width'))
    y_max = int(config.get(config_gui_section_name, 'height'))
    number_of_balls = int(config.get(config_initial_state_section_name, 'number_of_balls'))
    r_max = int(config.get(config_initial_state_section_name, 'max_ball_radius'))
    v_max = int(config.get(config_initial_state_section_name, 'max_ball_speed'))
    max_fps = int(config.get(config_gui_section_name, 'max_fps'))

    # Initialize arrays
    x_vals = np.zeros((number_of_balls,1))
    y_vals = np.zeros((number_of_balls,1))
    r_vals = r_max * np.random.rand(number_of_balls, 1)

    # Print info
    print("Parsed config file. Found the following settings:")
    print("--------------------------------------------------")
    print("Server IP: " + server_ip)
    print("Server Port: " + server_port)
    print("Window Width: " + str(x_max))
    print("Window Height: " + str(y_max))
    print("Max FPS: " + str(max_fps))
    print("Number of Balls: " + str(number_of_balls))
    print("Max Ball Radius: " + str(r_max))
    print("Max Ball Speed: " + str(v_max))
    print("--------------------------------------------------")

def setupZmqConnection():
    context = zmq.Context()
    global socket
    socket = context.socket(zmq.REQ)

    print("Connecting to Bouncing Balls server...")
    socket.connect("tcp://" + server_ip + ":" + server_port)
    print("Connected to server!")

# Creates a first stateUpdate at random given the number of balls and bounds
def initializeAtRandom():
    initialStateUpdate = ballProto.stateUpdate()

    for i in range(number_of_balls):
        ball = ballProto.Ball()
        ball.id = i+1;
        ball.x = x_max * rd.uniform(0, 1)        
        ball.y = y_max * rd.uniform(0, 1)
        ball.r = r_max * rd.uniform(0, 1) 
        ball.vx = v_max * rd.uniform(0, 1)
        ball.vy = v_max * rd.uniform(0, 1)
        
        # Put into the local storage
        x_vals[i] = ball.x
        y_vals[i] = ball.y
        r_vals[i] = ball.r        
        
        # Append ball to stateUpdate
        initialStateUpdate.balls.append(ball)

    initialStateUpdate.ballCount = number_of_balls
    initialStateUpdate.xMax = x_max
    initialStateUpdate.yMax = y_max
    
    return initialStateUpdate

# Main method
def main():
    # i = 0
    # time_stamp = time.time()
    parseConfigFile()
    setupZmqConnection()

    # Setup and plot initial state
    currentStateUpdate = initializeAtRandom()
    gui.initGui(x_max, y_max)
    gui.drawWindow(x_vals, y_vals, r_vals)
    print("Initial state: " + str(currentStateUpdate))

    # Running loop
    while (True):
        # Send update to server
        socket.send(currentStateUpdate.SerializeToString())
        print("Sent state update to server: " + str(currentStateUpdate))
        
        # Get answer from server
        answer = socket.recv()
        currentStateUpdate = ballProto.stateUpdate()
        currentStateUpdate.ParseFromString(answer)
        print("Received new state as reply: " + str(currentStateUpdate))
        
        # print("Received new state from server!")
        # i += 1
        # print("Handled " + str(i) + " messages in " + str(time.time() - time_stamp))

        # Save new x and y values for plotting
        for ballIndex, tmpBall in enumerate(currentStateUpdate.balls):
            x_vals[ballIndex] = tmpBall.x
            y_vals[ballIndex] = tmpBall.y

        gui.drawWindow(x_vals, y_vals, r_vals)
        time.sleep(1/max_fps)

if __name__ == "__main__":
    main()
