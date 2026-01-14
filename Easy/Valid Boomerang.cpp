#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-boomerang/
// Difficulty : Easy 

/* 
   PROBLEM IS JUST ASKING TO WRITE A PROGRAM THAT CHECKS IF ANY GIVEN 3 POINTS ARE COLINEAR OR NOT. 
   IF COLINEAR, ANSWER SHOULD BE FALSE, ELSE TRUE. THAT'S IT. 
*/

/* MATH + GEOMETRY */
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {

        double x01diff = abs(points[1][0] - points[0][0]);
        double y01diff = abs(points[1][1] - points[0][1]);
        double x02diff = abs(points[2][0] - points[0][0]);
        double y02diff = abs(points[2][1] - points[0][1]);
        double x12diff = abs(points[2][0] - points[1][0]);
        double y12diff = abs(points[2][1] - points[1][1]);

        if ((x01diff == 0 and y01diff == 0) or (x02diff == 0 and y02diff == 0) or (x12diff == 0 and y12diff == 0)) { return false; }

        double m1 = (x01diff) ? (y01diff / x01diff) : 1e15; 
        double m2 = (x02diff) ? (y02diff / x02diff) : 1e15;
        double m3 = (x12diff) ? (y12diff / x12diff) : 1e15;
        
        return !(m1 == m2 && m2 == m3);
    }
};