#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/angle-between-hands-of-a-clock/
// Difficulty : Medium

/* SIMPLE MATH BASED ON CLOCK */
class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hh_angle = hour*30 + minutes*0.5;
        double mh_angle = minutes*6;
        double angle_between = abs(hh_angle - mh_angle);

        return (angle_between > 180) ? 360 - angle_between : angle_between;
    }
};