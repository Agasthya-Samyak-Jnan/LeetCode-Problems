#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/course-schedule/
// Difficulty : Medium

/* TOPOLOGICAL SORT CONCEPT - TAKING DEPENDENT COURSES FIRST IN ORDER TO COMPLETE A COURSE. 
   COMPLETION OF COURSE NOT POSSIBLE IF A CYCLE EXISTS. i.e. IF TWO OR MORE COURSES ARE MUTUALLY DEPENDENT ON EACH OTHER TO COMPLETE.
   SO QUESTION IS BASICALLY : CHECK IF GIVEN DIRECTED GRAPH HAS CYCLES OR NOT.
   USED DEPTH-FIRST SEARCH TO FIND CYCLES IN THIS SOLUTION.
*/
class Solution {
public:
    bool dfs (vector<vector<int>>& g, int i, int& n, vector<int>& visited, vector<int>& r) {
        
        visited[i] = 1;
        r[i] = 1;
        
        for (auto j : g[i]) {
            if (!visited[j]) { if (dfs(g,j,n,visited,r)) { return true; } }
            else if (r[j]) { return true; }
        }
        
        r[i] = 0;
        return false;
    }  
    
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<vector<int>> g(n);
        vector<int> visited(n,0);
        vector<int> r(n,0);
        bool cyclic = false;
        
        for (auto i : p) {
            g[i[1]].push_back(i[0]); 
        }
        
        for (int i=0;i<n;i++) {
            if (!visited[i]) { cyclic = dfs(g,i,n,visited,r); }
        }
        
        return !cyclic;
    }
};