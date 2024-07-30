#!/bin/bash
protoc -I=. --cpp_out=../compiledProtos/cpp/ bouncingBallsMessages.proto

protoc -I=. --python_out=../compiledProtos/python/ bouncingBallsMessages.proto

cp ../compiledProtos/python/*.py ../frontend/.
