#include <iostream>
#include <time.h>
#include <random>
//#include <SFML/Graphics.hpp>

using namespace std;

struct Ball {
    double vx; // Velocity x
    double vy; // Velocity x
    double x; //  x position
    double y; //  y position
    double r; // radius
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 1.0);

    int no_balls = 10;
    double x_max = 700.0;
    double y_max = 400.0;
    double max_vx_initial = 4.0;
    double max_vy_initial = 4.0;
    double r_max = 10.0;

    Ball ballArray[no_balls];

    for (int i = 0; i < no_balls; i++) {
        ballArray[i].vx = dist(gen) * (max_vx_initial + max_vx_initial) - max_vx_initial;
        ballArray[i].vy = dist(gen) * (max_vy_initial + max_vy_initial) - max_vy_initial;
        ballArray[i].x = dist(gen) * (x_max );
        ballArray[i].y = dist(gen) * (y_max );
        ballArray[i].r = dist(gen) * (r_max );

        cout << "Ball: " << i << " - (x,y) = (" << ballArray[i].x << ", " << ballArray[i].y << ") - (vx,vy) = (" << ballArray[i].vx << ", " << ballArray[i].vx << ") - r = " << ballArray[i].r << endl;
    }


    return 0;
}
