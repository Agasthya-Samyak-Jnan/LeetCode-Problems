#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/course-schedule-iv/
// Difficulty : Medium 

/* BREADTH-FIRST SEARCH SOLUTION */
class Solution {
public:
    int n;
    
    void bfs (int i, vector<vector<int>>& g, vector<int>& visited) {
        
        int I = i;
        queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            i = q.front(); q.pop();
            if (visited[i]) { continue; }
            visited[i] = 1;
            for (int j=0;j<n;j++) { 
                if (g[i][j] && !visited[j]) { q.push(j); g[I][j] = 1; } 
            }
        }
        
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        this->n = n;
        vector<int> visited;
        vector<vector<int>> g(n,vector<int>(n,0));
        vector<bool> ans;
        
        for (auto& edge : prerequisites) { g[edge[0]][edge[1]] = 1; }
        
        for (int i=0;i<n;i++) { 
            visited = vector<int>(n,0);
            bfs(i,g,visited); 
        }
        
        for (auto query : queries) { ans.push_back(g[query[0]][query[1]]); }
        
        return ans;
    }
};

/* FLOYD-WARSHALL ALGORITHM SOLUTION */
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> g(n,vector<int>(n,0));
        vector<bool> ans;
        
        for (auto& edge : prerequisites) { g[edge[0]][edge[1]] = 1; }
        
        // Floyd-Warshall Algorithm
        for (int k=0;k<n;k++) { 
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    g[i][j] |= g[i][k] && g[k][j];
                }
            }
        }
        
        for (auto query : queries) { ans.push_back(g[query[0]][query[1]]); }
        
        return ans;
    }
};