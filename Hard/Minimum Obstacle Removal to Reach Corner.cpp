#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
// Difficulty : Hard

/* THIS CAN ALSO BE SOLVED USING BREADTH-FIRST SEARCH. */

/* DIJKISTRA'S ALOGRITHM : O(M*N*Log(M*N)) with CELLS OF MATRIX AS NODES and CELL VALUES as WEIGHTED EDGES. */
#define INF 1e9

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) {
        
        int m = g.size(), n = g[0].size(), cost, i, j;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> path(m,vector<int>(n,INF));
        vector<int> dx = {0,0,-1,+1};
        vector<int> dy = {-1,+1,0,0};
        
        path[0][0] = 0;
        pq.push({0,0,0});
        
        while (!pq.empty()) {
            
            auto curr = pq.top(); pq.pop();
            cost = curr[0];
            i = curr[1];
            j = curr[2];
            
            if (i == m-1 && j == n-1) { return cost; }
            
            if (cost > path[i][j]) { continue; }
            
            for (int k=0;k<4;k++) {
                
                int di = i + dx[k];
                int dj = j + dy[k];
                
                if (di>=0 && di<m && dj>=0 && dj<n) {
                    if (cost + g[di][dj] < path[di][dj]) {
                        path[di][dj] = cost + g[di][dj];
                        pq.push({path[di][dj],di,dj});
                    }
                }
            }
            
        }
        
        return path[m-1][n-1];
    }
};