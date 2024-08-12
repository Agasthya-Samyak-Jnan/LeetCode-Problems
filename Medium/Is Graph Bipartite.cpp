#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/is-graph-bipartite/
// Difficulty : Medium 


/* BREADTH-FIRST SEARCH : TWO-COLOR GRAPH COLORING METHOD TO CHECK BIPARTITENESS - EASY AND SIMPLE TO UNDERSTAND */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
         
        int n = g.size();
        
        vector<int> color(n,-1);
        queue<int> q;
        
        for (int i=0;i<n;i++) {
            if (color[i] == -1) {
                
                q.push(i);
                color[i] = 0;
                
                while (!q.empty()) {
            
                    int c = q.front(); q.pop();
                    int m = g[c].size();
                    
                    for (int i=0;i<m;i++) { 
                        
                        if (color[g[c][i]] == -1) { 
                            color[g[c][i]] = 1 - color[c]; 
                            q.push(g[c][i]);
                        }
                        else if (color[g[c][i]] == color[c]) { return false; }  
                        
                    }
                }
            }
            
        } 
    
        return true; 
    }
};