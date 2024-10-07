#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-closed-islands/
// Difficulty : Medium 

/* SIMPLE DEPTH-FIRST SEARCH SOLUTION */
class Solution {
public:
    int m,n,ans;
    vector<vector<int>> g;
    
    bool dfs (int i, int j) {
        
        g[i][j] = -1; // Mark Cell as Visited Cell.
        
        bool Left = 1, Right = 1, Up = 1, Down = 1;
        // Only Visit '0' Cells. (Land Cells)
        if (j>0 && g[i][j-1] == 0) { Left = dfs(i,j-1); } // Left
        if (i>0 && g[i-1][j] == 0) { Up = dfs(i-1,j); } // Up
        if (j<n-1 && g[i][j+1] == 0) { Right = dfs(i,j+1); } // Right
        if (i<m-1 && g[i+1][j] == 0) { Down = dfs(i+1,j); } // Down
        
        // If you are at edge of Grid while traversing any island, it is not closed.
        return (i != m-1 && j != n-1 && i != 0 && j != 0) && Left && Right && Down && Up; 
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        m = grid.size(); n = grid[0].size();
        ans = 0; g = grid;
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 0 && dfs(i,j))  { ans++; }
            }
        }
        
        return ans;
    }
};