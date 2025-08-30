#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-matrix-by-diagonals/
// Difficulty : Medium 

/* SIMULATION - DO WHAT THEY TELL YOU TO DO */
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size(), x;
        vector<int> diag = {};
        
        // Top Right Side Diagonals
        for (int k=n-1;k>0;k--) {

            int i = 0, j = k;
            while (i<m and j<n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }

            sort(diag.begin(),diag.end());

            i = 0, j = k, x = 0;
            while (i<m and j<n) {
                grid[i][j] = diag[x];
                i++; j++; x++;
            }

            diag.clear();
        }

        // Bottom Left Side Diagonals
        for (int k=0;k<m;k++) {

            int i = k, j = 0;
            while (i<m and j<n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }

            sort(diag.begin(),diag.end(), greater<int>());

            i = k, j = 0, x = 0;
            while (i<m and j<n) {
                grid[i][j] = diag[x];
                i++; j++; x++;
            }

            diag.clear();

        }

        return grid;
    }
};