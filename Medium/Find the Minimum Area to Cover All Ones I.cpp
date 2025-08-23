#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Difficulty : Medium 

/* SIMPLE INTUITION */
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    min_x = min(min_x, i);
                    max_x = max(max_x, i);
                    min_y = min(min_y, j);
                    max_y = max(max_y, j);
                }
            }
        }

        int area = (max_x - min_x + 1) * (max_y - min_y + 1);
        
        return area;
    }
};