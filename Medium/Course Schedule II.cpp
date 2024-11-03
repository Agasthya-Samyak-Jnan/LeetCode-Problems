#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/course-schedule-ii/
// Difficulty : Medium

/* TOPOLOGICAL SORTING OF GRAPH */
class Solution {
public:
    vector<int> ans;
    
    // Topological Sort - DFS
    // True indicates NOT POSSIBLE CONTAINS CYCLE.
    bool toposort (int i,vector<vector<int>>& g,vector<int>& visited,vector<int>& r,int n) {
        
        visited[i] = 1;
        r[i] = 1;
        
        for (auto j : g[i]) {
            if (!visited[j] && toposort(j,g,visited,r,n)) { return true; } 
            else if (r[j]) { return true; }
        }
        
        r[i] = 0;
        ans.push_back(i);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> g(n);
        vector<int> visited(n,0);
        vector<int> r(n,0);
        
        // Build the graph in our required format.
        for (auto i : prerequisites) { g[i[1]].push_back(i[0]); }
        
        // Start Topological Sort from every Unvisited Component.
        for (int i=0;i<n;i++) {
            if (!visited[i] && toposort(i,g,visited,r,n)) { return {}; }
        }
        
        // Reverse to get the correct order.
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};