#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-islands/
// Difficulty : Medium 

/* SIMPLE DEPTH-FIRST SEARCH */
class Solution {
public:
    int m,n,ans;
    vector<vector<char>> g;
    
    void dfs (int i, int j) {
        
        g[i][j] = '_'; // Mark Cell as Visited Cell.
        
        if (j>0 && g[i][j-1] == '1') { dfs(i,j-1); } // Left
        if (i>0 && g[i-1][j] == '1') { dfs(i-1,j); } // Up
        if (j<n-1 && g[i][j+1] == '1') { dfs(i,j+1); } // Right
        if (i<m-1 && g[i+1][j] == '1') { dfs(i+1,j); } // Down
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        ans = 0;
        g = grid;
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == '1') {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};