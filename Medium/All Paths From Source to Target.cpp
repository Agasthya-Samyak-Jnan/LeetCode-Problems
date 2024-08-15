#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/all-paths-from-source-to-target/
// Difficulty : Medium

/* DEPTH-FIRST-SEARCH WITH BACKTRACKING OF PATH WE FOLLOWED EACH TIME. */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void dfs(vector<vector<int>>& g,vector<int>& temp,int i) {
        
         temp.push_back(i); // Current node is in our path. Add it to path.
         if (i == g.size()-1) { ans.push_back(temp); } // Reached Target Node. No further nodes available to go to.
         else { for (auto j : g[i]) { dfs(g,temp,j); } }  // Basic DFS recursion. Go through all nodes one by one.
        
         temp.pop_back(); // BackTrack to Previous State
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        dfs(graph,temp,0);
        
        return ans;
        
    }
};