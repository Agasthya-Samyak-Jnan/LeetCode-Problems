#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
// DIfficulty : Hard

/* DEPTH-FIRST SEARCH + DYNAMIC PROGRAMMING : RECURSION WITH 2D MEMOIZATION - STRICTLY INCREASING VISITED CELLS SEQUENCES NEVER REPEAT */
class Solution {
public:
    int m, n, TOTAL_PATHS = 0, mod = 1e9 + 7;
    vector<vector<int>> drxns = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> g;
    unordered_map<int,unordered_map<int,int>> dp;

    int bfs (int i, int j) {

        if (dp.find(i) != dp.end() and dp[i].find(j) != dp[i].end()) { return dp[i][j]; }

        int paths = 1;

        for (auto d : drxns) {
            int x = i + d[0], y = j + d[1];
            if (!(x<0 or y<0 or x>=m or y>=n) and g[i][j] < g[x][y]) {
                paths = paths % mod + dfs(x,y) % mod;
            }
        }

        return dp[i][j] = paths;
    }

    int countPaths(vector<vector<int>>& g) {
        
        m = g.size(), n = g[0].size();
        this->g = g;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                TOTAL_PATHS = TOTAL_PATHS % mod + dfs(i,j) % mod;
            }
        }

        return TOTAL_PATHS;
    }
};

/* Indexing Optimization - Lesser/Similar Memory Usage but 1D Memoization */
class Solution {
public:
    int m, n, TOTAL_PATHS = 0, mod = 1e9 + 7;
    vector<vector<int>> drxns = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> g;
    unordered_map<int,int> dp;

    int dfs (int i, int j) {

        if (dp.find(n*i+j) != dp.end()) { return dp[n*i+j]; }

        int paths = 1;

        for (auto d : drxns) {
            int x = i + d[0], y = j + d[1];
            if (!(x<0 or y<0 or x>=m or y>=n) and g[i][j] < g[x][y]) {
                paths = paths % mod + dfs(x,y) % mod;
            }
        }

        return dp[n*i+j] = paths;
    }

    int countPaths(vector<vector<int>>& g) {
        
        m = g.size(), n = g[0].size();
        this->g = g;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                TOTAL_PATHS = TOTAL_PATHS % mod + dfs(i,j) % mod;
            }
        }

        return TOTAL_PATHS;
    }
};