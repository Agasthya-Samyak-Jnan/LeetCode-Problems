#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/critical-connections-in-a-network/
// Difficulty : Hard

/* 
    The most basic description of this question can be : "Find all bridges in the graph." 
    Bridge = An Edge that causes graph to split into two components when its removed from graph.
*/

/* 
    BRUTE FORCE : Remove every edge , check if graph is connected using DFS or BFS and then add the edge back to graph. Do this for every edge.
    Time Complexity : E*(V+E) , Where V = no.of.vertices, E = no.of.edges.
*/
class Solution {
public:
    vector<unordered_set<int>> g;
    vector<int> visited;
    int connected;
    
    /* Depth-First Search to check connectivity. */
    void check_connectivity (int i) {
        
        visited[i] = 1;
        connected++;
        
        for (auto& j : g[i]) { 
            if (!visited[j]) { check_connectivity(j); }
        }

    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> ans;
        
        // Build graph to your format
        g = vector<unordered_set<int>>(n);
        for (auto& edge : connections) { 
            g[edge[0]].insert(edge[1]); 
            g[edge[1]].insert(edge[0]);
        }
        
        for (auto edge : connections) {

            visited = vector<int>(n,0);
            connected = 0;
            // Remove Edge
            g[edge[0]].erase(edge[1]);
            g[edge[1]].erase(edge[0]);

            // Check if graph is connected
            check_connectivity(0);
            if (connected != n) { ans.push_back(edge); }

            // Add Back Edge
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);

        }
        
        return ans;
    }
};

/* TARJAN'S ALGORITHM TO FIND STRONGLY AND WAEKLY CONNECTED COMPONENTS IN A GRAPH USING DEPTH-FIRST SEARCH. */
class Solution {
public:
    vector<int> first,least,visited;
    vector<vector<int>> g, ans;
    int time = -1;

    // Tarjan's Algorithm to find Articulation Points and Bridges in a Graph.
    void dfs (int i, int parent) {

        visited[i] = 1;
        first[i] = least[i] = ++time;

        for (auto j : g[i]) {
            if (j == parent) { continue; }
            if (visited[j]) { least[i] = min(least[i],first[j]); }
            else {
                dfs(j,i);
                least[i] = min(least[i],least[j]);
                if (least[j] > first[i]) { ans.push_back({i,j}); }
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        g = vector<vector<int>>(n);
        for (auto& edge : connections) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        first = vector<int>(n,-1);
        least = vector<int>(n,-1);
        visited = vector<int>(n,0);

        for (int i=0;i<n;i++) {
            if (!visited[i]) { dfs(i,-1); }
        }
        
        return ans;
    }
};