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

# These are parameters of this world
number_of_balls = 100
x_max = 200
y_max = 150
r_max = 10

x_vals = np.zeros((100,1))
y_vals = np.zeros((100,1))
r_vals = r_max * np.random.rand(100, 1)

context = zmq.Context()
socket = context.socket(zmq.REQ)

print("Connecting to Bouncing Balls server...")
socket.connect("tcp://127.0.0.1:5555")
print("Connected to server!")

def main():
    currentStateUpdate = ballProto.stateUpdate()
    ball = ballProto.Ball()
    ball.x = 20
    ball.y = 10
    ball.r = 5
    ball_serialized = ball.SerializeToString()

    ball2 = ballProto.Ball()
    ball2.ParseFromString(ball_serialized)
 
    currentStateUpdate.balls.append(ball)
    currentStateUpdate.balls.append(ball2)

    print("Initial state: " + str(currentStateUpdate))
    socket.send(currentStateUpdate.SerializeToString())
    print("Sent state update to server!")
    
    answer = socket.recv()
    newState = ballProto.stateUpdate()
    newState.ParseFromString(answer)
    print("Received new state as reply: " + str(newState))

def initializeAtRandom():
    return    

if __name__ == "__main__":
    main()