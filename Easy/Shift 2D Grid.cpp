#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shift-2d-grid/
// Difficulty : Easy

/* MATRIX OPERATIONS */
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size(), elements  = m*n, p = 0;
        if (k % elements == 0) { return grid; }

        vector<vector<int>> ans(m, vector<int>(n));

        while (p<m*n) {
            ans[((p+k)%elements)/n][((p+k)%elements)%n] = grid[p/n][p%n];
            p++;
        }

        return ans;
    }
};