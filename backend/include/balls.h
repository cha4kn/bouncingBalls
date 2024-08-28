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

    void collideWallsCircle(int circleRadius)
    {
        if (std::sqrt(std::pow(x, 2) + std::pow(y, 2) + r) > circleRadius)
        {
            spdlog::debug("Collided ball with circle wall!");
            
            double theta = thetaAngle(x ,y); // Polar coordinates
            // Also move ball to precisely touch wall
            x = std::cos(theta) * (circleRadius - r);
            y = std::sin(theta) * (circleRadius - r);

            spdlog::debug("Collision theta is: " + std::to_string(theta*180.0/M_PI) + " degrees.");
            std::array<double, 2> normalVector = {-circleRadius * std::cos(theta), -circleRadius * std::sin(theta)}; // Points into circle
            spdlog::debug("Normal vector (x,y) = (" + std::to_string(normalVector[0])+ ","+std::to_string(normalVector[1]));

            std::array<double, 2> anglesVector = findIncidentAngleToNormal(normalVector, circleRadius);
            spdlog::debug("Incident angle was " + std::to_string(anglesVector[1]*180.0/M_PI) + " degrees.");
            setNewVelocity(normalVector, anglesVector);
            spdlog::debug("Calculated new velocity!");
        }
    }

    std::array<double, 2> findIncidentAngleToNormal(std::array<double, 2> normalVector, int circleRadius) {
        double angleBetween = std::acos((vx * normalVector[0] + vy * normalVector[1]) / 
        (std::sqrt(std::pow(vx, 2) + std::pow(vy, 2))*std::sqrt(std::pow(normalVector[0], 2) + std::pow(normalVector[1], 2))));
        double incidentAngle = M_PI - angleBetween; 
        return {angleBetween, incidentAngle};
    }

    double thetaAngle(double x_coord, double y_coord) {
        if (x_coord > 0) {
            if (y_coord > 0) {
                return std::atan(y_coord / x_coord);
            } else {
                return 2 * M_PI + std::atan(y_coord / x_coord);
            }
        } else if (x_coord < 0) {
            if (y_coord > 0) {
                return M_PI + std::atan(y_coord / x_coord);
            } else {
                return M_PI + std::atan(y_coord / x_coord);
            }
        } else if (x_coord == 0) {
            if (y_coord > 0) {
                return M_PI / 2;
            } else {
                return 3/2 * M_PI;
            }
        } else if (y_coord == 0) {
            if (x_coord > 0) {
                return 0;
            } else {
                return M_PI;
            }
        }
    }

    void setNewVelocity(std::array<double, 2> normalVector, std::array<double, 2> anglesVector) {
        // Find which side of normal the ball is on using cross product.
        // Find new velocity vector accordingly given the incidentAngle.
        bool crossProductSignNegative = std::signbit(std::sin(anglesVector[0]));
        double newTheta;
        if (crossProductSignNegative) { // Ball came from the left
            newTheta = thetaAngle(vx, vy) - (M_PI - 2 * anglesVector[1]);            
        } else { // Ball came from the right
            newTheta = thetaAngle(vx, vy) + (M_PI - 2 * anglesVector[1]);          
        }

        // Handle angle periodicity
        if (newTheta < 0)
        {
            newTheta += 2 * M_PI;
        }
        else if (newTheta > 2 * M_PI)
        {
            newTheta -= 2 * M_PI;
        }

        spdlog::debug("New theta angle is: " + std::to_string(newTheta));

        // Calculate new velocity vector
        double velocityAmp = std::sqrt(std::pow(vx, 2) + std::pow(vy, 2));
        vx = velocityAmp * std::cos(newTheta);
        vy = velocityAmp * std::sin(newTheta);
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
    bool rectangular;
    double radius;

public:
    State(int max_x, int max_y, bool rectangluar, double radius) : 
    max_x(max_x), max_y(max_y), rectangular(rectangular), radius(radius) {}

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

    bool getRectangular() {
        return rectangular;
    }

    double getRadius() {
        return 250;
    }
};

void performStateStepRectangular(State& state);

void performStateStepCircular(State& state);

void performBallStepRectangular(Ball& ball, double xMax, double yMax);

void performBallStepCircular(Ball& ball, double circleRadius);

void collideBalls(Ball& ball1, Ball& ball2);

std::array<double, 2> getDifferenceVector(Ball& ball1, Ball& ball2);

double distanceBetweenBalls(Ball& ball1, Ball& ball2);

void handleCompleteState(State& state);

#endif