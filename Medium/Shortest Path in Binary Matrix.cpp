#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH - LEVEL ORDER TRAVERSAL */
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& g) {
            
            int m = g.size(), n = g[0].size(), steps = 1;
    
            if (g[0][0] == 1 or g[m-1][n-1] == 1) { return -1; }
    
            queue<pair<int,int>> q;
            vector<vector<int>> visited(m,vector<int>(n,0));
            int directions[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}}; // 8-Directions
    
            q.push({0,0});
    
            while (!q.empty()) {
    
                int l = q.size();
    
                for (int i=0;i<l;i++) {
    
                    auto [x,y] = q.front(); q.pop();
    
                    if (x == m-1 and y == n-1) { return steps; } // Destination Reached
    
                    // Explore 1 Step in each of the 8-Directions.
                    for (auto d : directions) {
                        int dx = x + d[0], dy = y + d[1];
                        if (dx >= 0 and dy >= 0 and dx < m and dy < n and g[dx][dy] == 0 and !visited[dx][dy]) {
                            q.push({dx,dy});
                            visited[dx][dy] = 1;
                        }
                    }
    
                }
    
                steps++;
            }
            
            return -1;
        }
};