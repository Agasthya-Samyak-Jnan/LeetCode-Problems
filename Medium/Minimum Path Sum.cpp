#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-path-sum/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING - 2D-MATRIX = TABULATION METHOD DP */
/* Check if going Right is Minimum or Going Down is Minimum to arrive AT each cell. Table/Matrix represents this. */
/* Since each value in table represents Minimum Sum Value to arrive at each cell, 
   the minimum path sum to arrive at bottom-right most cell is its value in table. */
   
/* TC : O(m*n) , SC : O(m*n) */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                int minimum = INT_MAX;
                // Upper Cell
                if (i>0) { minimum = min(minimum,dp[i-1][j]); }
                // Left Cell
                if (j>0) { minimum = min(minimum,dp[i][j-1]); }
                // Min Sum
                if (minimum == INT_MAX) { minimum = 0; }
                dp[i][j] = grid[i][j] + minimum;
            }
        }      
        return dp[n-1][m-1];
    }
};