#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/total-distance-traveled/
// Difficulty : Easy

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int m = 0;
        int dist = 0;
        while (m < mainTank) {
            dist += 10;
            m++;
            if (m%5==0) { 
                if (additionalTank) { 
                    mainTank++; 
                    additionalTank--;
                }
            }
        }
        return dist;
    }
};