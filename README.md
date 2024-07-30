# bouncingBalls

Overview
===================================================

BouncingBalls is a simple program utilizing network communication to visualize a simulation of balls
moving within a rectangular area. There are two rules to this simulation:  

1. Balls bounce on walls
2. Balls collide with eachother

Most parameters of the simulation can be modified, such as world size, number of balls, ball sizes and speeds. 
The backend of this program is written in C++ and the frontend is done in Python. The program is written in 
such a way that it is possible to run the backend (server) on one computer and the frontend (client) on 
another computer on the same network. Additionally, the backend server can handle multiple frontend clients simultaneously.
Network message serialization is done utilizing Google protocol buffers. Network programming is done using ZeroMQ.

Below follows instructions on how to setup and run the program. At the bottom is a list of TODOs and IDEAs that will be added.

How to run
===================================================

Backend  
---------------------------------------------------
1. cd backend
2. mkdir build
3. cd build
4. cmake -S ..
5. make
6. ./BouncingBalls

Frontend  
---------------------------------------------------

**Requirements:**
1. python3
2. python venv
3. Internet connection to download repos using apt.

**Setup**  
1. Terminal: "cd frontend"
2. Terminal: ". setup_venv.sh" (*the preceding dot is important!*)
3. Edit the IP and port of the server within the script.

**Run**
1. Terminal: "python3 client.py"
2. Enjoy some BouncingBalls!

Future Work
===================================================

TODOs
---------------------------------------------------

1. Frontend: make pygame window more stable - right now it cannot be moved or closed without Windows reporting 
it as a crash.
2. Backend: introduce physically correct collision model.

IDEAs
---------------------------------------------------

1. Introduce statistics, such as number of collisions between balls and between walls that can be presented
in the GUI.
2. Introduce some extra mechanic, such as ball colors switching from collisions.
3. Make it possible for the user to manually set up the initial state in the GUI.
4. Add interface for user to edit game parameters instead of going by config file.
5. Add docker support for simple deployment!
