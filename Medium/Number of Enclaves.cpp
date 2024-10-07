#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-enclaves/
// Difficulty : Medium 

/* SIMPLE DEPTH-FIRST SEARCH SOLUTION */
class Solution {
public:
    int m,n,ans;
    bool touched_bound;
    vector<vector<int>> g;
    
    int dfs (int i, int j) {
        
        g[i][j] = -1; // Mark Cell as Visited Cell.
        
        int Left = 0, Right = 0, Up = 0, Down = 0;
        
        // Only Visit '1' Cells. (Land Cells)
        if (j>0 && g[i][j-1] == 1) { Left = dfs(i,j-1); } // Left
        if (i>0 && g[i-1][j] == 1) { Up = dfs(i-1,j); } // Up
        if (j<n-1 && g[i][j+1] == 1) { Right = dfs(i,j+1); } // Right
        if (i<m-1 && g[i+1][j] == 1) { Down = dfs(i+1,j); } // Down
        
        // If you are at edge of Grid while traversing any island, its Reachable.
        if (i == m-1 || j == n-1 || i == 0 || j == 0) { touched_bound = true; }
        
        // Only Count if this Component or Island is Unreachable.
        return touched_bound ? 0 : (1 + Left + Right + Up + Down);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        m = grid.size(); n = grid[0].size();
        g = grid; ans = 0;
        
        // Only Check Non-Boundary Cells.
        for (int i=1;i<m-1;i++) {
            for (int j=1;j<n-1;j++) {
                if (g[i][j] == 1) { 
                    touched_bound = false;
                    ans += dfs(i,j); 
                }
            }
        }
        
        return ans;
    }
};