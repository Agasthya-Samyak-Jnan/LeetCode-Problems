#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/count-sub-islands/
// Difficulty: Medium

using namespace std; 

/* SUB-ISLAND = CELLS OF A COMPONENT(OR ISLAND) IN G2 MUST ALL BELONG TO RESPECTIVE COMPONENT(OR ISLAND) IN G1, VICE-VERSA IS NOT NECESSARY. */

/* DEPTH-FIRST SEARCH (RECURSIVE) */
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    vector<vector<int>> g1, g2;
    vector<vector<int>> drxns = {{-1,0},{0,-1},{1,0},{0,1}};

    bool dfs (int i, int j) {

        visited[i][j] = 1;
        bool result = (g1[i][j] != 0);

        for (auto d : drxns) {
            int x = i + d[0], y = j + d[1];
            if (x>=0 and y>=0 and x<m and y<n and !visited[x][y] and g2[x][y] == 1) {
                bool temp = dfs(x,y);
                result = result && temp;
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid1.size(), n = grid1[0].size();
        int sub_islands = 0;
        visited = vector<vector<int>>(m, vector<int>(n,0));
        g1 = grid1;
        g2 = grid2;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i][j] and g2[i][j]) {
                    sub_islands += dfs(i,j);
                } 
            }
        }

        return sub_islands;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    vector<vector<int>> g1, g2;
    vector<vector<int>> drxns = {{-1,0},{0,-1},{1,0},{0,1}};

    bool bfs (int i, int j) {

        bool result = true;
        queue<pair<int,int>> q;

        q.push({i,j});
        visited[i][j] = 1;

        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            if (g1[i][j] == 0) { result = false; }
            for (auto d : drxns) {
                int x = i + d[0], y = j + d[1];
                if (x>=0 and y>=0 and x<m and y<n and !visited[x][y] and g2[x][y] == 1) {
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
        }

        return result;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        m = grid1.size(), n = grid1[0].size();
        int sub_islands = 0;
        visited = vector<vector<int>>(m, vector<int>(n,0));
        g1 = grid1;
        g2 = grid2;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i][j] and g2[i][j]) {
                    sub_islands += bfs(i,j);
                } 
            }
        }

        return sub_islands;
    }
};