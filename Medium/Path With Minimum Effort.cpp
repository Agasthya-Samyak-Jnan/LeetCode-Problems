#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/path-with-minimum-effort/
// Difficulty: Medium

using namespace std; 

/*  
    DFS -> BFS -> DIJKISTRA 
    BREADTH-FIRST SERCH + PRIORITY QUEUE = DIJKISTRA 
    ALWAYS APPLICABLE ON PROBLEMS THAT DIRECTLY OR INDIRECTLY REPRESENT WEIGHTED GRAPHS. 
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        
        int minEffort = 1e6, m = h.size(), n = h[0].size();
        vector<vector<int>> drxns = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> visited(m, vector<int>(n,1e6));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0}); // {effort,x,y}

        while (!pq.empty()) {

            int effort = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            if (i == m-1 and j == n-1) { minEffort = min(minEffort,effort); continue; }

            if (minEffort < effort) { continue; }

            for (auto d : drxns) {
                int di = i + d[0], dj = j + d[1];
                if (di>=0 and dj>=0 and di<m and dj<n) {
                    int newEffort = max(effort,abs(h[i][j]-h[di][dj]));
                    if (newEffort < visited[di][dj]) { 
                        pq.push({newEffort,di,dj}); 
                        visited[di][dj] = min(visited[di][dj],newEffort);
                    }
                }
            }
        }

        return minEffort;
    }
};