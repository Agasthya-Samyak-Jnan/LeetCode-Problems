#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shortest-cycle-in-a-graph/
// DIfficulty : Hard

/* ESSENCE OF BREADTH-FIRST SEARCH */

/* BREADTH-FIRST SEARCH : 
    - IF YOU REVISIT A NODE TWICE - THEN ITS PART OF A CYCLE. 
    - IF YOU START EXPLORING BREADTH-FIRST FROM A NODE THAT YOU KNOW IS PART OF A CYCLE, THEN YOU WILL EVENTUALLY TWO NEAREST SEARCHING ENDS WILL MEET AT NEAREST COMMON NODE WHERE THE SHORTEST CYCLE COMPLETES.
    - BREADTH-FIRST SEARCH IS INTELLIGENT BY NATURE : CONSIDER ALL CHOICES BEFORE MAKING THE NEXT CHOICE.
*/

class Solution {
    public:
    
        // Find Shortest Cycle including this "start" vertex.
        int shortestCycle (int start, int n, vector<vector<int>>& g) {
    
            int shortestLen = INT_MAX;
            queue<vector<int>> q;
            vector<int> found(n,0);
    
            q.push({start,0,-1});
            found[start] = -1;
    
            while (!q.empty()) {
    
                int curr = q.front()[0];
                int len = q.front()[1];
                int came_from = q.front()[2];
                q.pop();
    
                for (auto next : g[curr]) {
                    if (!found[next]) {
                        q.push({next,len+1,curr}); 
                        found[next] = len+1;
                    }
                    else if (next != came_from) { shortestLen = min(shortestLen,(found[next] + len + 1)); }
                }
    
            }
    
            return shortestLen;
        }
    
        int findShortestCycle(int n, vector<vector<int>>& edges) {

            vector<vector<int>> g(n);
            vector<int> visited(n,0);
            int cycleLength = INT_MAX; 
    
            // Build Adjacency List of Graph.
            for (auto e : edges) { 
                g[e[0]].push_back(e[1]);
                g[e[1]].push_back(e[0]);
            }
    
            // Peform BFS and find which vertices are part of a cycle. Vertices visited by a BFS twice are part of some cycles in graph.
            // For such vertices, Find the shortest cycle they are part of using AGAIN, BFS.
            for (int i=0;i<n;i++) {
    
                // Search for Cycles in Each Component.
                if (!visited[i]) {
                    
                    // BFS through this Component.
                    queue<pair<int,int>> q;
                    q.push({i,-1});
                    visited[i] = 1;
    
                    while (!q.empty()) {
    
                        auto [curr,came_from] = q.front(); q.pop();
    
                        for (auto next : g[curr]) {
                            if (!visited[next]) {
                                q.push({next,curr});
                                visited[next] = 1;
                            }
                            else if (next != came_from) { // A Vertex that is Member of a Cycle is found, find shortest cycle including it and check if its shorter cycle than those previously found cycles.
                                cycleLength = min(cycleLength,shortestCycle(next,n,g)); 
                            }
                        }
    
                    }
    
                }
            }
    
            return cycleLength == INT_MAX ? -1 : cycleLength;
        }
};