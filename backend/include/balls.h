#ifndef BALLS_H
#define BALLS_H

#include <spdlog/spdlog.h>

class Ball {
private:
    double x, y; //  x, y position
    double vx, vy; // Velocity x, y
    double r; // radius

public:
    Ball(double x, double y, double vx, double vy, double r) 
        : x(x), y(y), vx(vx), vy(vy), r(r) {}

    void stepForward () {
        x += vx;
        y += vy;
    }

    void collideWalls(int xMax, int yMax)
    {
        if ((x + r) > xMax)
        { // Right
            spdlog::debug("Collided ball with right wall!");
            reverseVelX();
            x = xMax - r;
        }
        else if ((x - r) < 0)
        { // Left
            spdlog::debug("Collided ball with left wall!");
            reverseVelX();
            x = r;
        }
        else if ((y + r) > yMax)
        { // Up
            spdlog::debug("Collided ball with top wall!");
            reverseVelY();
            y = yMax - r;
        }
        else if ((y - r) < 0)
        { // Down
            spdlog::debug("Collided ball with bottom wall!");
            reverseVelY();
            y = r;
        }
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    void setX(double newX) {
        x = newX;
    }

    void setY(double newY) {
        y = newY;
    }

    double getVx() {
        return vx;
    }

    double getVy() {
        return vy;
    }

    void setVx(double newVx) {
        vx = newVx;
    }

    void setVy(double newVy) {
        vy = newVy;
    }

    double getR() {
        return r;
    }

    void setR(double newR) {
        r = newR;
    }

    void reverseVelX() {
        vx *= -1;
    }

    void reverseVelY() {
        vy *= -1;
    }
};

class State {
private:
    std::vector<Ball> balls;
    int max_x, max_y;

public:
    State(int max_x, int max_y) : max_x(max_x), max_y(max_y) {}

    void addBall(const Ball& ball) {
        balls.push_back(ball);
    }

    std::vector<Ball>& getBalls() {
        return balls;
    }

    void setBalls(std::vector<Ball> newBalls) {
        balls = newBalls;
    }

    int getMaxX() const {
        return max_x;
    }

    int getMaxY() const {
        return max_y;
    }
};

void performStateStep(State& state);

void performBallStep(Ball& ball, double xMax, double yMax);

void collideBalls(Ball& ball1, Ball& ball2);

std::array<double, 2> getDifferenceVector(Ball& ball1, Ball& ball2);

double distanceBetweenBalls(Ball& ball1, Ball& ball2);

void handleCompleteState(State& state);

#endif