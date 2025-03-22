#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// Difficulty : Hard

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        int shortestPath(vector<vector<int>>& g, int K) {
            
            int steps = 0, m = g.size(), n = g[0].size();
            queue<vector<int>> q;
            vector<vector<int>> visited(m,vector<int>(n,-1));
            vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};
    
            q.push({0,0,K});
            visited[0][0] = K;
    
            while (!q.empty()) {
    
                int l = q.size();
    
                for (int p=0;p<l;p++) {
    
                    int x = q.front()[0], y = q.front()[1], k = q.front()[2];
                    q.pop();
    
                    if (x == m-1 and y == n-1) { return steps; }
                    
                    // ALWAYS DISCOVER PATHS IF YOU HAVE MORE OBSTACLES TO ELIMINATE
                    for (int i=0;i<4;i++) {
                        if (x+dx[i] >= 0 and y+dy[i] >= 0 and x+dx[i] < m and y+dy[i] < n) {
                            if (k >= 0 and k > visited[x+dx[i]][y+dy[i]]) {
                                if (g[x+dx[i]][y+dy[i]] == 1) { 
                                    q.push({x+dx[i],y+dy[i],k-1}); 
                                    visited[x+dx[i]][y+dy[i]] = k-1; 
                                }
                                else {
                                    q.push({x+dx[i],y+dy[i],k}); 
                                    visited[x+dx[i]][y+dy[i]] = k; 
                                }
                            }
                        } 
                    }
    
                }
    
                steps++;
            }
    
            return -1;
        }
};