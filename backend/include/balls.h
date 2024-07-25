#ifndef BALLS_H
#define BALLS_H

struct Ball {
    double vx; // Velocity x
    double vy; // Velocity x
    double x; //  x position
    double y; //  y position
    double r; // radius
};

void performStateStep(Ball* ballArray, int ballCount, double xMax, double yMax);

void performBallStep(Ball* ballPointer, double xMax, double yMax);

void collideWalls(Ball* ballPointer, double xMax, double yMax);

void collideBalls(Ball* ballPointer1, Ball* ballPointer2);

double* getDifferenceVector(Ball* ballPointer1, Ball* ballPointer2);

void stepBallForward(Ball* ballPointer);

double distanceBetweenBalls(Ball* ballPointer1, Ball* ballPointer2);

void reverseVelX(Ball* ballPointer);

void reverseVelY(Ball* ballPointer);

void handleCompleteState(int ballCount, double* xValues, double* yValues, double* xVelocities, double* yVelocities, double* rValues, double xMax, double yMax);

#endif