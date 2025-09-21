#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/island-perimeter/
// Difficulty : Easy 

/* DEPTH-FIRST SEARCH - RECURSIVE */
class Solution {
public:
    vector<vector<int>> grid, visited;
    int m,n;

    int dfs (int x, int y) {
        visited[x][y] = 1;
        int perimeter = 0;
        perimeter += (x+1 >= m or grid[x+1][y] == 0) ? 1 : (!visited[x+1][y]) ? dfs(x+1,y) : 0; 
        perimeter += (y+1 >= n or grid[x][y+1] == 0) ? 1 : (!visited[x][y+1]) ? dfs(x,y+1) : 0; 
        perimeter += (x-1 < 0 or grid[x-1][y] == 0) ? 1 : (!visited[x-1][y]) ? dfs(x-1,y) : 0; 
        perimeter += (y-1 < 0 or grid[x][y-1] == 0) ? 1 : (!visited[x][y-1]) ? dfs(x,y-1) : 0; 
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        this->grid = grid;
        visited = vector<vector<int>>(m,vector<int>(n,0));
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) { return dfs(i,j); }
            }   
        }

        return -1;
    }
};

/* DEPTH-FIRST SEARCH - ITERATIVE */
class Solution {
public:

    int dfs (int x, int y, vector<vector<int>>& grid, int m, int n) {

        vector<vector<int>> visited = vector<vector<int>>(m,vector<int>(n,0));
        stack<pair<int,int>> s;
        int perimeter = 0;

        s.push({x,y});
        visited[x][y] = 1;

        while (!s.empty()) {

            auto [x,y] = s.top(); s.pop();

            if (x+1 >= m or grid[x+1][y] == 0) { perimeter++; }
            else if (!visited[x+1][y]) { s.push({x+1,y}); visited[x+1][y] = 1; }

            if (y+1 >= n or grid[x][y+1] == 0) { perimeter++; }
            else if (!visited[x][y+1]) { s.push({x,y+1}); visited[x][y+1] = 1; }

            if (x-1 < 0 or grid[x-1][y] == 0) { perimeter++; } 
            else if (!visited[x-1][y]) { s.push({x-1,y}); visited[x-1][y] = 1; }

            if (y-1 < 0 or grid[x][y-1] == 0) { perimeter++; } 
            else if (!visited[x][y-1]) { s.push({x,y-1}); visited[x][y-1] = 1; }

        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        
        for (int x=0;x<m;x++) {
            for (int y=0;y<n;y++) {
                if (grid[x][y]) { return dfs(x,y,grid,m,n); }
            }   
        }

        return -1;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:

    int bfs (int x, int y, vector<vector<int>>& grid, int m, int n) {

        vector<vector<int>> visited = vector<vector<int>>(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int perimeter = 0;

        q.push({x,y});
        visited[x][y] = 1;

        while (!q.empty()) {

            auto [x,y] = q.front(); q.pop();

            if (x+1 >= m or grid[x+1][y] == 0) { perimeter++; }
            else if (!visited[x+1][y]) { q.push({x+1,y}); visited[x+1][y] = 1; }

            if (y+1 >= n or grid[x][y+1] == 0) { perimeter++; }
            else if (!visited[x][y+1]) { q.push({x,y+1}); visited[x][y+1] = 1; }

            if (x-1 < 0 or grid[x-1][y] == 0) { perimeter++; } 
            else if (!visited[x-1][y]) { q.push({x-1,y}); visited[x-1][y] = 1; }

            if (y-1 < 0 or grid[x][y-1] == 0) { perimeter++; } 
            else if (!visited[x][y-1]) { q.push({x,y-1}); visited[x][y-1] = 1; }

        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        
        for (int x=0;x<m;x++) {
            for (int y=0;y<n;y++) {
                if (grid[x][y]) { return bfs(x,y,grid,m,n); }
            }   
        }

        return -1;
    }
};