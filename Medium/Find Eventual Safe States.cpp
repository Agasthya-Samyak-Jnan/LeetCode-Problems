#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-eventual-safe-states/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH */
class Solution {
    public:
        vector<vector<int>> g;
        vector<int> inCurrPath, visited, safe_nodes;
    
        bool safe (int i) {
            // If we know already if this Node is Safe or Not Safe, return the memorized result.
            if (visited[i] != -1) { return visited[i]; }
    
            inCurrPath[i] = 1; // To check if revisit a place in the path we are still exploring (similar to detecting cycles in graphs)
    
            for (auto j : g[i]) {
                if (inCurrPath[j] or !safe(j)) { return visited[i] = 0; } // Existence of just 1 Path leading to Nodes that are NOT safe makes THIS node Unsafe.
            }
    
            inCurrPath[i] = 0; // After exploring this path, we are NOT here anymore.
            return visited[i] = 1; // Terminal Node OR All Paths lead to safe nodes.
        }
    
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            
            int n = graph.size();
            g = graph;
            inCurrPath = vector<int>(n,0);
            visited =  vector<int>(n,-1);
    
            // Check every Node if its Safe in Ascending Order.
            for (int i=0;i<n;i++) {
                if (safe(i)) { safe_nodes.push_back(i); }
            }
    
            return safe_nodes;
        }
};