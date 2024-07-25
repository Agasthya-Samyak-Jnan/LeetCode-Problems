#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
// Difficulty : Medium

/* Can be Solved Using Breadth-First-Search , Depth-First-Search and Topological Sort */
/* HERE SOLVED USING DEPTH-FIRST-SEARCH (DFS) */

/* Runtime : 2617 ms - RAW APPROACH */
class Solution {
public:

    int E;
    vector<vector<int>> g;
    vector<int> visited;

    void dfs (int a) {

        visited[a] = 1;
        for (int i=E-1;i>=0;i--) {
            if (g[i][0] == a && visited[g[i][1]] == 0) {
                dfs(g[i][1]);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        g = edges;
        E = edges.size();
        vector<vector<int>> ANS(n,vector<int>(0,0)); 

        for (int i=0;i<E;i++) { swap(g[i][0],g[i][1]); }
 
        for (int i=0;i<n;i++) { 
            visited = vector<int>(n,0);
            dfs(i);
            for (int j=0;j<n;j++) { if(visited[j] == 1 && i != j) { ANS[i].push_back(j); } }
        }
        
        return ANS;
    }
};

/* Runtime : 430 ms - OPTIMISED BY CONVERTING EDGES-LIST TO ADJACENCY-LIST - adjList[[]] */
class Solution {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> ans;
    int n = n;
    
    void dfs (int ancestor, int current) {

        for (auto i : adjList[current]) {
            if (find(ans[i].begin(),ans[i].end(),ancestor) == ans[i].end()) { ans[i].push_back(ancestor); dfs(ancestor,i); }
        }
      
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        adjList = vector<vector<int>>(n);
        ans = vector<vector<int>>(n);
        this->n = n;
        
        // Create Adjacency-List From Edge-List.
        for (auto i : edges) { adjList[i[0]].push_back(i[1]); }

        // Do DFS , All nodes found From a Given Node have this Given Node as One of thier Ancestors.
        for (int i=0;i<n;i++) { dfs(i,i); }
        
        return ans;
    }
};

/* Runtime : 85 ms - OPTIMISED CHECK CONDITION FOR AVOIDING REPEATED ADDITION OF ANCESTORS LIST OF NODES - REMOVED find() */
class Solution {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> ans;
    int n = n;
    
    void dfs (int ancestor, int current) {
        for (auto i : adjList[current]) {
            if (ans[i].empty() || ans[i].back() != ancestor) { ans[i].push_back(ancestor); dfs(ancestor,i); }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        adjList = vector<vector<int>>(n);
        ans = vector<vector<int>>(n);
        this->n = n;
        
        // Create Adjacency-List From Edge-List.
        for (auto i : edges) { adjList[i[0]].push_back(i[1]); }

        // Do DFS , All nodes found From a Given Node have this Given Node as One of thier Ancestors.
        for (int i=0;i<n;i++) { dfs(i,i); }
        
        return ans;
    }
};

// TESTER CODE
int main () {
    Solution* a = new Solution();
    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    vector<vector<int>> ans = a->getAncestors(8,edges);
    cout<<"[";
    for (auto i : ans) {
        cout<<"[";
        for (auto j : i) {
            cout<<j<<" ";
        }
        cout<<"],";
    }
    cout<<"]";
    return 0;
}