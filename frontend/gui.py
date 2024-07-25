# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 10:59:47 2023

@author: Arvid
"""

import matplotlib.pyplot as plt
import time
import numpy as np
plt.ion()

fig, ax = plt.subplots()

def plotAllBalls(max_x, max_y, ball_x, ball_y, ball_r):
    # Clear any previous data
    ax.clear()

    # Show new data
    ax.scatter(ball_x[np.nonzero(ball_x)], ball_y[np.nonzero(ball_y)])

    ax.set_xlim([-0.1*max_x, 1.1*max_x])
    ax.set_ylim([-0.1*max_y, 1.1*max_y])
    ax.set_xlabel("x")
    ax.set_ylabel("y")
    ax.set_title("Bouncing Balls")

    plt.draw()
    plt.pause(0.01)
    plt.show(block=True)
    
def plotBallsTmp(max_x, max_y, balls_x, balls_y):
    plt.figure()
    plt.scatter(balls_x[np.nonzero(balls_x)], balls_y[np.nonzero(balls_y)])
    plt.xlim([-0.1*max_x, 1.1*max_x])
    plt.ylim([-0.1*max_y, 1.1*max_y])
    plt.draw()
    plt.pause(0.01)
    plt.show()
      
    
    