#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-provinces/
// Difficulty : Medium

/* Apply Depth-First Search to Count Number of Connected Components in a Graph - How to Detect Disconnections in Graph. */
class Solution {
public:
    void dfs (vector<vector<int>>& g, int i, int n, vector<int>& visited) {
        
        visited[i] = 1;
        
        for (int j=0;j<n;j++) {
            if (i != j && g[i][j] && !visited[j]) { dfs(g,j,n,visited); }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n,0);
        
        for (int i=0;i<n;i++) {
            if (!visited[i]) { provinces++; dfs(isConnected,i,n,visited); }
        }
        
        return provinces;
    }
};