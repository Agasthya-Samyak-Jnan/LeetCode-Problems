#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
class Solution {
public:
    vector<vector<int>> g;
    int m,n;
    vector<int> dxn;
    
    int solve (int i, int j) {
        if (j == n-1) { return 1; }
        int ans = 0, k = i+2;
        for (auto dx : dxn) {
            if ((i+dx) >= 0 && (i+dx) < m && g[i][j] < g[i+dx][j+1]) { 
                ans = max(ans,solve(i+dx,j+1)); 
            }
        }
        return 1+ans;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size(), n = grid[0].size();
        dxn = {-1,0,1};
        
        int ans = 0;
        
        for (int i=0;i<m;i++) {
            ans = max(ans,solve(i,0));
        }
        
        return ans-1;
    }
};

/* RECURSION WITH MEMOISATION SOLUTION (2D MEMOISATION) */
class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> dp;
    int m,n;
    vector<int> dxn;
    
    int solve (int i, int j) {
        if (j == n-1) { return 1; }
        if (dp[i][j] != -1) { return dp[i][j]; }
        int ans = 0, k = i+2;
        for (auto dx : dxn) {
            if ((i+dx) >= 0 && (i+dx) < m && g[i][j] < g[i+dx][j+1]) { 
                ans = max(ans,solve(i+dx,j+1)); 
            }
        }
        dp[i][j] = 1 + ans;
        return dp[i][j];
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size(), n = grid[0].size();
        dxn = {-1,0,1};
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        
        int ans = 0;
        
        for (int i=0;i<m;i++) {
            ans = max(ans,solve(i,0));
        }
        
        return ans-1;
    }
};

/* ITERATIVE WITH TABULATION SOLUTION (2D TABULATION) */
class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<int> dxn = {-1,0,1};
        vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n,-1));
        
        int ans = 0;
        
        for (int i=0;i<m;i++) { dp[i][0] = 0; }
        
        for (int j=0;j<n-1;j++) {
            for (int i=0;i<m;i++) {
                if (dp[i][j] > -1) {
                    for (auto dx : dxn) {
                        if ((i+dx) < m && (i+dx) >= 0 && g[i][j] < g[i+dx][j+1]) { 
                            dp[i+dx][j+1] = 1 + dp[i][j]; 
                            ans = max(ans,1 + dp[i][j]);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

