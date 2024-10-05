#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-servers-that-communicate/
// Difficulty : Medium

/* DEPTH-FIRST SEARCH ON MATRIX */
class Solution {
public:
    vector<vector<int>> g;
    int m,n;
    
    int dfs (int i, int j, int d) { 
        
        if (i>=m || j>=n || i<0 || j<0 || g[i][j] == 0) { return 0; }
        
        int sum = 1;
        g[i][j] = 0;
        
        // Row-Only Search
        if (d == 2 || d == 0) {
            for (int k=0;k<n;k++) {
                if (g[i][k] == 1) { sum += dfs(i,k,1); }
            }
        }
        
        // Column-Only Search
        if (d == 2 || d == 1) {
            for (int k=0;k<m;k++) {
                if (g[k][j] == 1) { sum += dfs(k,j,0); }
            }
        }
        
        return sum;
    }
    
    
    int countServers(vector<vector<int>>& grid) {
        
        m = grid.size(), n = grid[0].size();
        g = grid;
        
        int sum = 0;
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] == 1) {
                    int temp = dfs(i,j,2);
                    if (temp != 1) { sum += temp; }
                }
            }
        }
        
        return sum;
    }
};