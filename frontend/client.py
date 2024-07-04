# -*- coding: utf-8 -*-
"""
Created on Thu Jul  4 13:47:13 2024

@author: afors
"""

import zmq
import time
import gui


ctx = zmq.Context().instance()
socket = ctx.socket(zmq.SUB)
socket.connect("tcp://localhost:5555")
socket.setsockopt(zmq.SUBSCRIBE, b"UPDATE")



def main():
    print(gui.plotAllBalls())
    while True:
        message = socket.recv()
        print("Received message: %s", message)
        time.sleep(2000)
        
        socket.send(b"Poops")



if __name__ == "__main__":
    main()


