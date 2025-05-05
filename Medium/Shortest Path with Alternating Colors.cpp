#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/3sum/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH : IF YOU DON'T KNOW WHICH COLOR EDGE YOU CAME FROM WHICH TO START FROM '0', TRY BOTH CASES. */
class Solution {
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            
            vector<vector<vector<int>>> g(n);
            vector<int> path(n,-1);
            vector<vector<int>> visited(n,vector<int>(2,0));
            int dist = 0;
            
            for (auto e : redEdges) { g[e[0]].push_back({e[1],0}); }      
            for (auto e : blueEdges) { g[e[0]].push_back({e[1],1}); }
            
            queue<vector<int>> q;
            q.push({0,0}); // Assuming came to '0' from Red Edge (This ignores all Blue Edge Paths outgoing from start)
            q.push({0,1}); // Assuming came to '0' from Blue Edge (This ignores all Red Edge Paths outgoing from start)
            visited[0][0] = 1;
            visited[0][1] = 1;
            
            while (!q.empty()) {
                
                int l = q.size();
                
                for (int i=0;i<l;i++) {
                    
                    int node = q.front()[0], edgecol = q.front()[1];
                    q.pop();
                
                    path[node] = (path[node] == -1) ? dist : path[node];
                
                    for (auto e : g[node]) {
                        if (!visited[e[0]][e[1]]) {
                            if (e[1] != edgecol) {
                                q.push({e[0],e[1]});
                                visited[e[0]][e[1]] = 1;
                            }
                        }
                    }
                }
                
                dist++;
            }
            
            return path;
        }
};