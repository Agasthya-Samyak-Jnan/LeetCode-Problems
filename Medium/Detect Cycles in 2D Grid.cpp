#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Difficulty : Medium

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<char>> g;
    vector<vector<int>> visited;
    int m,n;
    
    bool dfs (int i, int j, int pi, int pj, char curr) {
        
        // CYCLE FOUND!
        if (visited[i][j]) { return true; }
        
        visited[i][j] = 1;
        bool is_cyclic = false;
        
        // Up
        if (i-1 >= 0 && g[i-1][j] == curr && (i-1 != pi || j != pj)) { 
            is_cyclic = is_cyclic || dfs(i-1,j,i,j,curr); 
        }
        // Right
        if (j+1 < n && g[i][j+1] == curr && (i != pi || j+1 != pj)) { 
            is_cyclic = is_cyclic || dfs(i,j+1,i,j,curr); 
        }
        // Down
        if (i+1 < m  && g[i+1][j] == curr && (i+1 != pi || j != pj)) { 
            is_cyclic = is_cyclic || dfs(i+1,j,i,j,curr); 
        }
        // Left
        if (j-1 >= 0 && g[i][j-1] == curr && (i != pi || j-1 != pj)) { 
            is_cyclic = is_cyclic || dfs(i,j-1,i,j,curr); 
        }
        
        return is_cyclic;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<int>>(m,vector<int>(n,0));
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i][j]) {
                    // visited = vector<vector<int>>(m,vector<int>(n,0));
                    // The above resetting is not needed because, if this visited cell is a part of a cycle,
                    // it would have been detected previously including this cell, and we would have not have made it to this call.
                    if (dfs(i,j,-1,-1,g[i][j])) { return true; }
                }
            }
        }
        
        return false;
    }
};