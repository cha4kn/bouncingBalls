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

void stepBallForward(Ball* ballPointer);

void reverseVelX(Ball* ballPointer);

void reverseVelY(Ball* ballPointer);

void collideWalls(Ball* ballPointer);

void collideBalls(Ball* ballPointer1, Ball* ballPointer2);

double distanceBetweenBalls(Ball* ballPointer1, Ball* ballPointer2);

double* getDifferenceVector(Ball* ballPointer1, Ball* ballPointer2);

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    Ball ballArray[no_balls];

    // Initialization of balls
    for (int i = 0; i < no_balls; i++) {
        ballArray[i].r = dist(gen) * (r_max );
        ballArray[i].vx = dist(gen) * (max_vx_initial + max_vx_initial) - max_vx_initial;
        ballArray[i].vy = dist(gen) * (max_vy_initial + max_vy_initial) - max_vy_initial;
        ballArray[i].x = dist(gen) * (x_max - ballArray[i].r) + ballArray[i].r;
        ballArray[i].y = dist(gen) * (y_max - ballArray[i].r) + ballArray[i].r;

        cout << "Ball: " << i << " - (x,y) = (" << ballArray[i].x << ", " << ballArray[i].y << ") - (vx,vy) = (" << ballArray[i].vx << ", " << ballArray[i].vy << ") - r = " << ballArray[i].r << endl;
    }

    // Start bouncing!!!!
    while (true) {
        // Bounce against walls
        Ball* ptr = ballArray;
        for (int i = 0; i < no_balls; i++) {
            stepBallForward((ptr+i));
            cout << "Ball: " << i << " - (x,y) = (" << ballArray[i].x << ", " << ballArray[i].y << ") - (vx,vy) = (" << ballArray[i].vx << ", " << ballArray[i].vy << ") - r = " << ballArray[i].r << endl;

//            cout << "Colliding ball " << i << " with walls" << endl;
            collideWalls((ptr + i));
//            this_thread::sleep_for(chrono::milliseconds(200));

            // Collide with other balls
            for (int j = i+1; j < no_balls; j++) {
 //               cout << "Colliding ball " << i << " with ball " << j << endl;
//                this_thread::sleep_for(chrono::milliseconds(100));
                if (i == j) { // Don't collide ball with itself
                    break;
                } else {
                    collideBalls((ptr+i), (ptr+j));
                }
            }
        }
    }
    return 0;
}

// Collide a ball with any walls, changing its velocity as needed
// and repositioning it accordingly.
void collideWalls(Ball* ballPointer) {
    if ((ballPointer->x +  ballPointer->r) > x_max) { // Right
        cout << "Collided ball with right wall!" << endl;
        reverseVelX(ballPointer);
        ballPointer->x = (x_max - ballPointer->r);
    } else if ((ballPointer->x - ballPointer->r) < 0){ // Left
        cout << "Collided ball with left wall!" << endl;
        reverseVelX(ballPointer);
        ballPointer->x = ballPointer->r;
    } else if ((ballPointer->y +  ballPointer->r) > y_max) { // Up
        cout << "Collided ball with top wall!" << endl;
        reverseVelY(ballPointer);
        ballPointer->y = (y_max - ballPointer->r);
    } else if ((ballPointer->y - ballPointer->r) < 0) { // Down
        cout << "Collided ball with bottom wall!" << endl;
        reverseVelY(ballPointer);
        ballPointer->y = ballPointer->r;
    }
}

// See if two balls are close enough to collide, and if they are
// update velocity (simple model)
void collideBalls(Ball* ballPointer1, Ball* ballPointer2) {
    if (distanceBetweenBalls(ballPointer1, ballPointer2) < (ballPointer1->r + ballPointer2->r)) {
        cout << "Collision between balls detected!" << endl;
        double velAmp1 = sqrt(pow(ballPointer1->vx, 2) + pow(ballPointer1->vy, 2));
        double velAmp2 = sqrt(pow(ballPointer2->vx, 2) + pow(ballPointer2->vy, 2));

        double* vectorDiff = getDifferenceVector(ballPointer1, ballPointer2);

        // Change the velocities
        cout << "Changing velocities!" << endl;
        ballPointer1->vx = -velAmp1 * vectorDiff[0];
        ballPointer1->vy = -velAmp1 * vectorDiff[1];

        ballPointer2->vx = velAmp2 * vectorDiff[0];
        ballPointer2->vy = velAmp2 * vectorDiff[1];
    }
}

// Returns the unit vector from ball 1 to ball 2.
double* getDifferenceVector(Ball* ballPointer1, Ball* ballPointer2) {

    double diffX = ballPointer2->x - ballPointer1->x;
    double diffY = ballPointer2->y - ballPointer1->y;

    double ampDiff = sqrt(pow(diffX, 2) + pow(diffY, 2));

    cout << "Collision distance: " << ampDiff << endl;

    double* result = new double[2];
    result[0] = diffX / ampDiff;
    result[1] = diffY / ampDiff;
    return result;
}


void stepBallForward(Ball* ballPointer) {
    ballPointer->x += ballPointer->vx;
    ballPointer->y += ballPointer->vy;
}

double distanceBetweenBalls(Ball* ballPointer1, Ball* ballPointer2) {
    return sqrt(pow(ballPointer1->x - ballPointer2->x, 2) + pow(ballPointer1->y - ballPointer2->y, 2));
}

// Changes x-direction of ball 180 deg
void reverseVelX(Ball* ballPointer) {
    ballPointer->vx *= -1;
}

// Changes y-direction of ball 180 deg
void reverseVelY(Ball* ballPointer) {
    ballPointer->vy *= -1;
}
