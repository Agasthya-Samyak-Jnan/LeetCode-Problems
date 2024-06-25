#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/generate-random-point-in-a-circle/
// Difficulty : Medium

class Solution {
    double r, xc, yc;
public:
    Solution(double radius, double x_center, double y_center) : r(radius), xc(x_center), yc(y_center) {
        srand(time(0));
    }

    double f_rand () {
        return (double)rand()/RAND_MAX;
    }

    vector<double> randPoint() {
        double R = sqrt(f_rand())*r, deg = 2*M_PI*f_rand(); // We Know that, any point (x,y) in a circle can be represented as,
        double x = xc + R*cos(deg);  // x = Rcos(theta) - theta = degree in radians
        double y = yc + R*sin(deg);  // y = Rsin(theta) - R = radius of circle,  By Polar Coordinates System.
        return {x,y}; // square root of random is done for uniform distribution.
    }
};