#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/unique-paths-ii/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        
        int m = g.size(), n = g[0].size();
        if (g[0][0] == 1 || g[m-1][n-1] == 1) { return 0; }
        
        // Mark Obstacles differently
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                g[i][j] = g[i][j] == 1 ? -1 : 0;
            }
        }
        
        // Solve using DP
        g[0][0] = 1;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j] != -1) {
                    if (i < m-1 && g[i+1][j] != -1) { g[i+1][j] += g[i][j]; }
                    if (j < n-1 && g[i][j+1] != -1) { g[i][j+1] += g[i][j]; }
                }
            }
        }
                 
        return g[m-1][n-1];  
    }
};