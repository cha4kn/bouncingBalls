# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 13:47:13 2024

@author: afors
"""

import zmq
import time
import sys
import numpy as np
import gui
import bouncingBallsMessages_pb2 as ballProto
import random as rd
import configparser as cp
import math

# Config file parameters
config_file_name = "config.txt"
config_comm_section_name = "COMM"
config_gui_section_name = "GUI"
config_initial_state_section_name = "INITIAL STATE"
allowed_shapes = ["rectangle", "circle"]

# --------- Setup -------------------------------------------------------------
def parseConfigFile():
    global number_of_balls
    global x_max
    global y_max
    global r_min
    global r_max
    global v_min
    global v_max
    global server_ip
    global server_port
    global x_vals
    global y_vals
    global r_vals
    global max_fps
    global world_shape
    global circle_radius

    config = cp.ConfigParser()
    config.read_file(open(config_file_name))

    # Parse config file key value pairs
    server_ip = config.get(config_comm_section_name, 'server_ip')
    server_port = config.get(config_comm_section_name, 'server_port')
    world_shape = config.get(config_gui_section_name, 'world_shape')
    circle_radius = int(config.get(config_gui_section_name, 'circle_radius'))
    x_max = int(config.get(config_gui_section_name, 'width'))
    y_max = int(config.get(config_gui_section_name, 'height'))
    number_of_balls = int(config.get(config_initial_state_section_name, 'number_of_balls'))
    r_min = int(config.get(config_initial_state_section_name, 'min_ball_radius'))
    r_max = int(config.get(config_initial_state_section_name, 'max_ball_radius'))
    v_min = int(config.get(config_initial_state_section_name, 'min_ball_speed'))
    v_max = int(config.get(config_initial_state_section_name, 'max_ball_speed'))
    max_fps = int(config.get(config_gui_section_name, 'max_fps'))
    
    # Sanity check
    if(sanityCheckParameters() != True):
        print("Found error in runtime parameters!")
        sys.exit(1)
    
    # Initialize arrays
    x_vals = np.zeros((number_of_balls,1))
    y_vals = np.zeros((number_of_balls,1))
    r_vals = r_max * np.random.rand(number_of_balls, 1)

    # Print info
    print("Parsed config file. Found the following settings:")
    print("--------------------------------------------------")
    print("Server IP: " + server_ip)
    print("Server Port: " + server_port)
    print("World Shape: " + world_shape)
    print("Rect Width: " + str(x_max))
    print("Rect Height: " + str(y_max))
    print("Circle Radius: " + str(circle_radius))
    print("Max FPS: " + str(max_fps))
    print("Number of Balls: " + str(number_of_balls))
    print("Min Ball Radius: " + str(r_min))
    print("Max Ball Radius: " + str(r_max))
    print("Min Ball Speed: " + str(v_min))
    print("Max Ball Speed: " + str(v_max))
    print("--------------------------------------------------")

def sanityCheckParameters() -> bool:
    if (number_of_balls < 1):
        print("Number of balls needs to be at least 1!")
        return False
        
    if (x_max < 1):
        print("x_max needs to be at least 1!")
        return False
    
    if (y_max < 1):
        print("y_max needs to be at least 1!")
        return False
    
    if (r_min < 1):
        print("r_min needs to be at least 1!")
        return False

    if (r_max < 1):
        print("r_max needs to be at least 1!")
        return False
  
    if (r_min >= r_max):
        print("r_max needs to be bigger than r_min!")
        return False

    if (v_min < 1):
        print("v_min needs to be at least 1!")
        return False

    if (v_max < 1):
        print("v_max needs to be at least 1!")
        return False
  
    if (v_min >= v_max):
        print("v_max needs to be bigger than v_min!")
        return False
    
    if (max_fps < 1):
        print("max_fps needs to be at least 1!")
        return False
    
    if (world_shape not in allowed_shapes):
        print("world_shape: " + world_shape + " is not supported!")
        print("Supported world shapes are: " + ', '.join(allowed_shapes))
        return False
    
    if (circle_radius < 1):
        print("circle_radius needs to be at least 1!")
        return False
    
    if (r_max > circle_radius):
        print("r_max cannot be larger than circle_radius!")
        return False
    
    return True

def setupZmqConnection():
    context = zmq.Context()
    global socket
    socket = context.socket(zmq.REQ)

    print("Connecting to Bouncing Balls server...")
    socket.connect("tcp://" + server_ip + ":" + server_port)
    print("Connected to server!")

# Creates a first stateUpdate at random given the number of balls and bounds
def initializeAtRandomRect():
    initialStateUpdate = ballProto.stateUpdate()

    for i in range(number_of_balls):
        ball = ballProto.Ball()
        ball.id = i+1;
        ball.x = x_max * rd.uniform(0, 1)        
        ball.y = y_max * rd.uniform(0, 1)
        ball.r = r_min + (r_max - r_min) * rd.uniform(0, 1)
        ball.vx = v_min + (v_max - v_min ) * rd.uniform(0, 1)
        ball.vy = v_min + (v_max - v_min ) * rd.uniform(0, 1)
        
        # Put into the local storage
        x_vals[i] = ball.x
        y_vals[i] = ball.y
        r_vals[i] = ball.r        
        
        # Append ball to stateUpdate
        initialStateUpdate.balls.append(ball)

    initialStateUpdate.ballCount = number_of_balls
    initialStateUpdate.xMax = x_max
    initialStateUpdate.yMax = y_max
    initialStateUpdate.worldShape = world_shape
    
    return initialStateUpdate

# Creates a first stateUpdate at random given the number of balls and bounds
def initializeAtRandomCirc():
    initialStateUpdate = ballProto.stateUpdate()

    for i in range(number_of_balls):
        ball = ballProto.Ball()
        ball.id = i+1;
        angle = rd.uniform(0, 2*math.pi)
        distance = circle_radius * rd.uniform(0, 0.9)
        ball.x = distance * np.cos(angle)
        ball.y = distance * np.sin(angle)
        ball.r = r_min + (r_max - r_min) * rd.uniform(0, 1)
        ball.vx = v_min + (v_max - v_min ) * rd.uniform(0, 1)
        ball.vy = v_min + (v_max - v_min ) * rd.uniform(0, 1)
        
        # Put into the local storage
        x_vals[i] = ball.x
        y_vals[i] = ball.y
        r_vals[i] = ball.r        
        
        # Append ball to stateUpdate
        initialStateUpdate.balls.append(ball)

    initialStateUpdate.ballCount = number_of_balls
    initialStateUpdate.circleRadius = circle_radius    
    initialStateUpdate.worldShape = world_shape
    
    return initialStateUpdate

# Main method
def main():
    # i = 0
    # time_stamp = time.time()
    parseConfigFile()
    setupZmqConnection()
    
    if (world_shape == "rectangle"):
        # Setup and plot initial state
        currentStateUpdate = initializeAtRandomRect()
        gui.initGuiRect(x_max, y_max)
        gui.drawWindowRect(x_vals, y_vals, r_vals)
        
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

            gui.drawWindowRect(x_vals, y_vals, r_vals)
            time.sleep(1/max_fps)
    else:
        # Setup and plot initial state
        currentStateUpdate = initializeAtRandomCirc()
        gui.initGuiCirc(circle_radius)
        gui.drawWindowCirc(x_vals, y_vals, r_vals, circle_radius)
        
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

            gui.drawWindowCirc(x_vals, y_vals, r_vals, circle_radius)
            time.sleep(1/max_fps)

if __name__ == "__main__":
    main()
