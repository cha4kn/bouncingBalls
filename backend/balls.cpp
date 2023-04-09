#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

// Variables
int no_balls = 10;
double x_max = 700.0;
double y_max = 400.0;
double max_vx_initial = 4.0;
double max_vy_initial = 4.0;
double r_max = 10.0;

struct Ball {
    double vx; // Velocity x
    double vy; // Velocity x
    double x; //  x position
    double y; //  y position
    double r; // radius
};

void repositionBall(Ball* ballPointer);

void reverseVelX(Ball* ballPointer);

void reverseVelY(Ball* ballPointer);

void collideWalls(Ball* ballPointer);

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    Ball ballArray[no_balls];

    // Initialization of balls
    for (int i = 0; i < no_balls; i++) {
        ballArray[i].vx = dist(gen) * (max_vx_initial + max_vx_initial) - max_vx_initial;
        ballArray[i].vy = dist(gen) * (max_vy_initial + max_vy_initial) - max_vy_initial;
        ballArray[i].x = dist(gen) * (x_max );
        ballArray[i].y = dist(gen) * (y_max );
        ballArray[i].r = dist(gen) * (r_max );

        cout << "Ball: " << i << " - (x,y) = (" << ballArray[i].x << ", " << ballArray[i].y << ") - (vx,vy) = (" << ballArray[i].vx << ", " << ballArray[i].vx << ") - r = " << ballArray[i].r << endl;
    }

    // Start bouncing!!!!
    while (true) {
        // Bounce against walls
        Ball* ptr = ballArray;
        for (int i = 0; i < no_balls; i++) {
            cout << "Colliding walls for ball no " << i << "with address: " << (ptr+i) << endl;
            collideWalls((ptr + i));
//            this_thread::sleep_for(chrono::milliseconds(1000));
        }


    }
    return 0;
}

// Collide a ball with any walls, changing its velocity as needed
// and repositioning it accordingly.
void collideWalls(Ball* ballPointer) {
    if ((ballPointer->x +  ballPointer->r) > x_max) { // Right
        reverseVelX(ballPointer);
        ballPointer->x = (x_max - ballPointer->r);
    } else if ((ballPointer->x - ballPointer->r) < 0){ // Left
        reverseVelX(ballPointer);
        ballPointer->x = ballPointer->r;
    } else if ((ballPointer->y +  ballPointer->r) > y_max) { // Up
        reverseVelY(ballPointer);
        ballPointer->y = (y_max - ballPointer->r);
    } else if ((ballPointer->y - ballPointer->r) < 0) { // Down
        reverseVelY(ballPointer);
        ballPointer->y = ballPointer->r;
    }
}

// Changes x-direction of ball 180 deg
void reverseVelX(Ball* ballPointer) {
    ballPointer->x *= -1;
}

// Changes y-direction of ball 180 deg
void reverseVelY(Ball* ballPointer) {
    ballPointer->y *= -1;
}
