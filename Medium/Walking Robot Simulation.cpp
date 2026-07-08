#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/walking-robot-simulation
// Difficulty : Medium

/* SIMULATION + HASH TABLES to keep obstacle positions in memory */
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int x = 0, y = 0, d = 0, max_dist = 0;
        vector<vector<int>> dxns = {{0,1},{1,0},{0,-1},{-1,0}};
        unordered_map<int,unordered_map<int,int>> obsts;

        for (auto o : obstacles) { obsts[o[0]][o[1]] = 1; }

        for (auto c : commands) {
            if (c > 0) {
                int steps = c;
                while (steps) {
                    int dx = x + dxns[d][0];
                    int dy = y + dxns[d][1];
                    if (obsts[dx][dy] == 1) { break; }
                    x = dx;
                    y = dy;
                    steps--;
                }
                max_dist = max(max_dist, x*x + y*y);
            }
            else {
                if (c == -1) { d = (d+1) % 4; } 
                if (c == -2) { d = (d+3) % 4; } // Same as [ d = (d-1+4) % 4 ]
            }
        }
        
        return max_dist;
    }
};