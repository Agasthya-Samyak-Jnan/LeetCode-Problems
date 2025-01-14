#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Difficulty : Medium

/* GRAPH THEORY : Any node with a indegree is reachable from some or the other node, given graph is always connected. */
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n,0), ans;
        for (auto& e : edges) { indegree[e[1]]++;  }
        for (int i=0;i<n;i++) { if (indegree[i] == 0) { ans.push_back(i); } }

        return ans;
    }
};