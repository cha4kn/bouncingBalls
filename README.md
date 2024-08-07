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
**Requirements:**
1. libprotoc v.3.6.1 installed (sudo apt install protobuf-compiler)
2. zeromq core library installed (https://github.com/zeromq/libzmq)

By default, backend will use port 5555 on localhost. To change this you need to edit the server.cpp and do the Setup step below.

**Setup:**
1. git submodule update --init --recursive
2. cd backend
3. mkdir build
4. cd build
5. cmake -S ..
6. make

**Run**  
./BouncingBalls

Frontend  
---------------------------------------------------

**Requirements:**
1. python3
2. python venv
3. Internet connection to download repos using apt.

**Setup**  
1. Terminal: "cd frontend"
2. Terminal: ". setup_venv.sh" (*the preceding dot is important!*)
3. Edit any run parameters inside the config.txt file.

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
