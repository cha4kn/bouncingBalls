# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 13:47:13 2024

@author: afors
"""

import zmq
import time
import numpy as np
import gui
import sys
import bouncingBallsMessages_pb2 as ballProto
import matplotlib.pyplot as plt
import random as rd

# Parameters of the ball world
number_of_balls = 100
x_max = 200
y_max = 150
r_max = 5
v_max = 2 # Applies similarly to x and y velocities

# --------- Setup -------------------------------------------------------------
x_vals = np.zeros((number_of_balls,1))
y_vals = np.zeros((number_of_balls,1))
r_vals = r_max * np.random.rand(number_of_balls, 1)

context = zmq.Context()
socket = context.socket(zmq.REQ)

print("Connecting to Bouncing Balls server...")
socket.connect("tcp://127.0.0.1:5555")
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
        
        # Put into our local storage
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
    
    # Setup and plot initial state
    currentStateUpdate = initializeAtRandom()
    gui.plotBallsTmp(x_max, y_max, x_vals, y_vals)
    print("Initial state: " + str(currentStateUpdate))

    # Running loop
    while (True):
        socket.send(currentStateUpdate.SerializeToString())
        print("Sent state update to server: " + str(currentStateUpdate))
        answer = socket.recv()
        
        currentStateUpdate = ballProto.stateUpdate()
        currentStateUpdate.ParseFromString(answer)
        
        print("Received new state as reply: " + str(currentStateUpdate))
        # print("Received new state from server!")
        # i += 1
        # print("Handled " + str(i) + " messages in " + str(time.time() - time_stamp))

        i = 0
        for tmpBall in currentStateUpdate.balls:
            x_vals[i] = tmpBall.x
            y_vals[i] = tmpBall.y
            i += 1

        gui.plotBallsTmp(x_max, y_max, x_vals, y_vals)
        time.sleep(0.3)

if __name__ == "__main__":
    main()