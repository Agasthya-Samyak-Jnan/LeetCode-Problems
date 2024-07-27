#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-graph-with-shortest-path-calculator/
// Difficulty : Hard

/* THIS CAN BE SOLVED USING [ PRIORITY QUEUE + DIJKISTRA'S ALGORITHM ] OR [ FLOYD-WARSHALL'S ALGORITHM ] , the difference is,
   1. If (ShortestPath) is called MORE than (AddEdge) then FLOYD-WARSHALL is preferred.
   2. If (AddEdge) is called MORE than (ShortestPath) then DIJKISTRA is preferred.

/* FLOYD-WARSHALL'S ALL PAIRS SHORTEST PATH - DESIGN FOR MULTIPLE CALLS DURING RUNTIME
   Time Complexity : O(n^2) for Adding Edge , O(1) - for Shortest Path Access */
class Graph {
public:
    
    vector<vector<int>> g;
    int n;
    
    Graph(int n, vector<vector<int>>& edges) {
        
        this->n = n;
        g = vector<vector<int>>(n,vector<int>(n,1e9));
        
        /* Initialise Directed Graph from Given Edge-List */
        for (auto i : edges) { g[i[0]][i[1]] = i[2]; }
        for (int i=0;i<n;i++) { g[i][i] = 0; }
        
        /* Initialise Graph with Shortest Paths First at Construction itself */
        for (int k=0;k<n;k++) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        
    }
    
    void addEdge(vector<int> edge) {
        /* Update Edge Only if its Lesser than Current Cost - IF YOU UPDATE THIIS, THEN YOU NEED TO UPDATE ALL PATHS THAT HAVE THIS EDGE IN-BETWEEN */
         if (g[edge[0]][edge[1]] > edge[2]) {
        /* Update the Given Edge First - DOING THIS FIRST IS IMPORTANT WE ARE USING THIS VALUE BELOW */
             g[edge[0]][edge[1]] = edge[2];
        /* Update Paths to Shortest Paths that have this "newly added edge" as thier Intermediate Vertex */
             for (int i=0;i<n;i++) {
                 for (int j=0;j<n;j++) {
                     g[i][j] = min(g[i][j],g[i][edge[0]]+g[edge[0]][edge[1]]+g[edge[1]][j]);
                 }
             }   
         } 
    }
    
    int shortestPath(int node1, int node2) {
        /* This is Because WE HAVE AGREED WITHIN OURSELVES THAT OUR GRAPH ALWAYS MAINTAINS 
           SHORTEST PATH COSTS BETWEEN EVERY PAIR AT ANY GIVEN TIME, HENCE GIVE IT DIRECTLY */
        return g[node1][node2] == 1e9 ? -1 : g[node1][node2] ;    
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */