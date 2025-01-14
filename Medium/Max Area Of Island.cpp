#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/max-area-of-island/
// Difficulty : Medium

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> g;
    int m,n;

    int dfs (int i, int j) {
        if (i>=m or j>=n or j<0 or i<0 or !g[i][j]) { return 0; }
        g[i][j] = 0; // Mark Visited cells within matrix itself!
        return 1+dfs(i+1,j)+dfs(i,j+1)+dfs(i-1,j)+dfs(i,j-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        g = grid;
        m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j]) {
                    ans = max(ans,dfs(i,j));
                }
            }
        }

        return ans;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    vector<vector<int>> g;
    int m,n;

    int bfs (int a, int b) {
        
        queue<pair<int,int>> q;
        int cells = 0;

        q.push({a,b});
        g[a][b] = 0;

        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            cells++;
            if (j+1 < n and g[i][j+1]) { q.push({i,j+1}); g[i][j+1] = 0; }
            if (i+1 < m and g[i+1][j]) { q.push({i+1,j}); g[i+1][j] = 0; }
            if (i-1 >= 0 and g[i-1][j]) { q.push({i-1,j}); g[i-1][j] = 0; }
            if (j-1 >= 0 and g[i][j-1]) { q.push({i,j-1}); g[i][j-1] = 0; }
        }

        return cells;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        g = grid;
        m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (g[i][j]) {
                    ans = max(ans,bfs(i,j));
                }
            }
        }

        return ans;
    }
};
