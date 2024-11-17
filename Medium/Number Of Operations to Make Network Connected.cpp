#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Difficulty : Medium 

// This can be solved by Union-Find , Depth-First Search and Breadth-First Search.

/* UNION-FIND BASED SOLUTION */
class UFS {
public:
    // Disjoint Set Data Structures
    int components;
    vector<int> parent;

    // Initialise Disjoint Set
    UFS (int n) {
        components = n;
        parent = vector<int>(n);
        iota(parent.begin(),parent.end(),0);
    }

    // Combine/Union thier Families
    void Union (int a, int b) {  
        int A = find(a), B = find(b);
        if (A == B) { return; }
        parent[B] = A;
        components--;
    }

    // Find Upper-Most Parent 
    int find (int a) {  
        return parent[a] = (a == parent[a]) ? a : find(parent[a]);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();      
        if (c < n-1) { return -1; }
        
        UFS ufs(n);
        
        for (auto& edge : connections) {
            ufs.Union(edge[0],edge[1]);
        }
        
        return ufs.components - 1;
    }
};

/* DEPTH-FIRST SEARCH BASED SOLUTION */
class Solution {
public:
    
    void dfs (int i, vector<vector<int>>& g, vector<int>& visited) {
        visited[i] = 1;
        for (auto j : g[i]) { if (i != j && !visited[j]) { dfs(j,g,visited); } }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (c < n-1) { return -1; }
        
        vector<vector<int>> g(n);
        
        // Build the Graph according to your CONVENIENCE (Note : Graph edges are BI-DIRECTIONAL)
        for (auto& edge : connections) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n,0);
        int components = 0;
        
        // Number of Times DFS called here is same as Number of Components in this network.
        for (int i=0;i<n;i++) {
            if (!visited[i]) { dfs(i,g,visited); components++; }
        }
        
        // To connect 'x' points , you will need at least (minimum) 'x-1' lines.
        return components-1;
    }
};

/* BREADTH-FIRST SEARCH BASED SOLUTION */
class Solution {
public:
    
    void bfs (int i, vector<vector<int>>& g, vector<int>& visited) {
        
        queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            i = q.front(); q.pop();
            if (visited[i]) { continue; }
            visited[i] = 1;
            for (auto j : g[i]) { q.push(j); }
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int c = connections.size();
        if (c < n-1) { return -1; }
        
        vector<vector<int>> g(n);
        
        // Build the Graph according to your CONVENIENCE (Note : Graph edges are BI-DIRECTIONAL)
        for (auto& edge : connections) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(n,0);
        int components = 0;
        
        // Number of Times DFS called here is same as Number of Components in this network.
        for (int i=0;i<n;i++) {
            if (!visited[i]) { bfs(i,g,visited); components++; }
        }
        
        // To connect 'x' points , you will need at least (minimum) 'x-1' lines.
        return components-1;
    }
};