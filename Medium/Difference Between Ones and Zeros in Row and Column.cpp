#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
// Difficulty : Medium

/* Simulate the Given Question , but do it efficiently */
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<int> onesRow(m,0), onesCol(n,0);
        
        // Rows 1s
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                onesRow[i] += grid[i][j];
            }
        }
        
        // Cols 1s
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                onesCol[i] += grid[j][i];
            }
        }
        
        // Build Diff Matrix
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                grid[i][j] = 2*onesRow[i] + 2*onesCol[j] - m - n;
            }
        }
         
        return grid;
    }
};