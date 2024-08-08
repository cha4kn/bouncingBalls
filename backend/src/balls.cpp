#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>
#include <balls.h>
#include <spdlog/spdlog.h>

using namespace std;

// Variables only used for testing
int no_balls = 10;
double x_max = 700.0;
double y_max = 400.0;
double max_vx_initial = 4.0;
double max_vy_initial = 4.0;
double r_max = 10.0;

void testRun() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    Ball* ballArray;

    // Initialization of balls
    for (int i = 0; i < no_balls; i++) {
        ballArray[i].setR(dist(gen) * (r_max ));
        ballArray[i].setVx(dist(gen) * (max_vx_initial + max_vx_initial) - max_vx_initial);
        ballArray[i].setVy(dist(gen) * (max_vy_initial + max_vy_initial) - max_vy_initial);
        ballArray[i].setX(dist(gen) * (x_max - ballArray[i].getR()) + ballArray[i].getR());
        ballArray[i].setY(dist(gen) * (y_max - ballArray[i].getR()) + ballArray[i].getR());

        cout << "Ball: " << i << " - (x,y) = (" << ballArray[i].getX() << ", " << ballArray[i].getY() << ") - (vx,vy) = (" << ballArray[i].getVx() << ", " << ballArray[i].getVy() << ") - r = " << ballArray[i].getR() << endl;
    }

    // Start bouncing!!!!
    while (true) {
        // Bounce against walls
        for (int i = 0; i < no_balls; i++) {
            spdlog::debug("Stepping ball " + to_string(i) + " forward.");
            ballArray[i].stepForward();

            spdlog::debug("Colliding ball " + to_string(i) + " with walls.");
            ballArray[i].collideWalls(x_max, y_max);

            // Collide with other balls
            spdlog::debug("Checking for ball collisions... ");
            for (int j = i+1; j < no_balls; j++) {
                if (i == j) { // Don't collide ball with itself
                    break;
                } else {
                    collideBalls(ballArray[i], ballArray[j]);
                }
            }
        }
    }
}

void performStateStep(State& state) {
    std::vector<Ball> theBalls = state.getBalls();
    int xMax = state.getMaxX();
    int yMax = state.getMaxY();
    int count = theBalls.size();
    for (int i = 0; i < count; i++) {
        Ball& currentBall = theBalls[i];
        performBallStep(currentBall, xMax, yMax); // Step forward and handle walls
        for (int j = i+1; j < count; j++) { // Handle collisions with other balls
            if (i == j) { // Don't collide ball with itself
                break;
            } else {
                collideBalls(currentBall, theBalls[j]);
            }
        }
    }
    state.setBalls(theBalls);
}

// Steps the ball forward and collides with walls
void performBallStep(Ball& ball, double xMax, double yMax) {
    ball.stepForward();
    ball.collideWalls(xMax, yMax);
}

// See if two balls are close enough to collide, and if they are
// update velocity (simple model)
// *** I have hired my beloved gf to consult me on a proper physical bounce model
void collideBalls(Ball& ball1, Ball& ball2) {
    if (distanceBetweenBalls(ball1, ball2) <= (ball1.getR() + ball2.getR())) {
        spdlog::debug("Collision between balls detected!");
        double velAmp1 = sqrt(pow(ball1.getVx(), 2) + pow(ball1.getVy(), 2));
        double velAmp2 = sqrt(pow(ball2.getVx(), 2) + pow(ball2.getVy(), 2));

        array<double, 2> vectorDiff = getDifferenceVector(ball1, ball2);

        // Change the velocities
        spdlog::debug("Changing velocities!");
        ball1.setVx(-velAmp1 * vectorDiff[0]);
        ball1.setVy(-velAmp1 * vectorDiff[1]);

        ball2.setVx(velAmp2 * vectorDiff[0]);
        ball2.setVy(velAmp2 * vectorDiff[1]);
    }
}

// Returns the unit vector from ball 1 to ball 2.
array<double, 2> getDifferenceVector(Ball& ball1, Ball& ball2) {

    double diffX = ball2.getX() - ball1.getX();
    double diffY = ball2.getY() - ball1.getY();

    double ampDiff = sqrt(pow(diffX, 2) + pow(diffY, 2));

    spdlog::debug("Collision distance: " + std::to_string(ampDiff));

    return {diffX / ampDiff, diffY / ampDiff};
}

double distanceBetweenBalls(Ball& ball1, Ball& ball2) {
    return sqrt(pow(ball1.getX() - ball2.getX(), 2) + pow(ball1.getY() - ball2.getY(), 2));
}

void handleCompleteState(State& state) {
    // Perform the actual calculation for this step
    spdlog::debug("Performing a step...");
    performStateStep(state); // TODO: restructure this method
    spdlog::debug("Step completed!");
}