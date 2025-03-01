#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rotting-oranges/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        int orangesRotting(vector<vector<int>>& g) {
            
            queue<pair<int,int>> q;
            int time = 0, fruits = 0;
            int m = g.size(), n = g[0].size();
            vector<int> dx = {1,0,-1,0}, dy = {0,1,0,-1};
    
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (g[i][j] == 2) { q.push({i,j}); }
                    fruits += (g[i][j] == 1);
                }
            }
    
            while (!q.empty() and fruits > 0) {
    
                int l = q.size();
                for (int k=0;k<l;k++) {
                    auto [i,j] = q.front(); q.pop();
                    for (int a=0;a<4;a++) {
                        if (i+dx[a] < m and i+dx[a] >= 0 and j+dy[a] < n and j+dy[a] >= 0 and g[i+dx[a]][j+dy[a]] == 1) {
                            g[i+dx[a]][j+dy[a]] = 2; 
                            q.push({i+dx[a],j+dy[a]});
                            fruits--;
                        }
                    }
                }
                time++;
            }
    
            return fruits > 0 ? -1 : time;
        }
    };