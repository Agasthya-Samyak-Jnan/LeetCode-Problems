#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Difficulty : Easy

/* SLOPE OF A STRAIGHT LINE IS SAME BETWEEN ANY TWO POINTS ON IT. AVOID DIVISION OPERATOR. */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& p) {
        
        int x0 = p[0][0], y0 = p[0][1], x1 = p[1][0], y1 = p[1][1];
        int dx = x1 - x0, dy = y1 - y0, n = p.size();
        
        for (int i=1;i<n;i++) {
            x1 = p[i][0], y1 = p[i][1];
            if ((x1-x0)*dy != (y1-y0)*dx) { return false; }
        }
        
        return true;
    }
};

