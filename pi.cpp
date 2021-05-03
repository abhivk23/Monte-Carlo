// Abhiram Kakuturu
// Monte Carlo Pi Estimation

#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>

#define PRECIS 100000

int main(int argc, char** argv){
    time_t seed = (argc>1) ? atoi(argv[1]) : time(NULL);
    srand(seed);

    std::ofstream output;
    output.open("Output/trial_data.txt");
    output << "Estimate" << "," << "Trial Number" << std::endl; 

    double x, y, hit_dist;
    double hits = 0.0;
    float pi = 4.0;

    // test convergence to system defined value of M_PI within 10E-5
    double i=0;
    while (fabs(pi-M_PI) > 0.0001 && i<PRECIS) {
        i+=1.0;
        // Generate x and y coordinates of each trial in the range [0,1]
        x = double(rand() % (PRECIS + 1)) / PRECIS;
        y = double(rand() % (PRECIS + 1)) / PRECIS;

        hit_dist = x*x + y*y;
        hits += (hit_dist <=1) ? 1.0 : 0.0;

        pi = 4.0 * hits/i;
        output << pi << "," << i << std::endl;
    }
    std::cout << "Final estimation of pi: " << pi << std::endl;
    std::cout << "Number of trials to convergence within 10E-5 precision: " << i << std::endl;
    return 0;
}