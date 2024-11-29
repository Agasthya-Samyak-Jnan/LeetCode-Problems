#include<bits/stdc++.h>
#define INF 1e9

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
// Difficulty : Hard

/* DIJKISTRA'S ALGORITHM with CELL VALUES AS EDGE WEIGHTS AND CELLS AS NODES. */

class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {
        
        if (g[0][1] > 1 && g[1][0] > 1) { return -1; } // Unreachable Starting itself.
        
        int m = g.size(), n = g[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> path(m,vector<int>(n,INF));
        vector<int> dx = {-1,+1,0,0};
        vector<int> dy = {0,0,-1,+1};
        int time,i,j;
        
        path[0][0] = 0;
        pq.push({0,0,0});
        
        while (!pq.empty()) {
            
            auto curr = pq.top(); pq.pop();
            i = curr[1];
            j = curr[2];
            time = curr[0];
            
            if (i == m-1 && j == n-1) { return time; }
            
            if (time > path[i][j]) { continue; }
            
            for (int k=0;k<4;k++) {
                
                int di = i + dx[k];
                int dj = j + dy[k];
                
                if (di>=0 && di<m && dj>=0 && dj<n) {
                    
                    int wait_time = (g[di][dj] - time) % 2 == 1 ? 0 : 1; //
                    int new_time = max(time + 1 , g[di][dj] + wait_time); //
                    
                    if (new_time < path[di][dj]) {
                        path[di][dj] = new_time;
                        pq.push({new_time, di, dj});
                    }
                }
            }
            
        }
        
        return -1;
    }
};