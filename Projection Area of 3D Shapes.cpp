#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/projection-area-of-3d-shapes/
// Difficulty: Easy


/* Time Complexity: O(N^2) */
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        
        int mxz = INT_MIN, myz = INT_MIN, xy = 0, xz = 0, yz = 0;
        int m = grid.size(), n = grid[0].size();
        
        for (int i=0;i<m;i++) {
            mxz = myz = INT_MIN;
            for (int j=0;j<n;j++) {
                if (grid[i][j]) { 
                    xy++; 
                    if (mxz < grid[i][j]) { mxz = grid[i][j]; }
                }
                if (myz < grid[j][i]) { myz = grid[j][i]; }
            }
            xz += mxz, yz += myz;
        }
        return xy+xz+yz;
    }
};