#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-town-judge/
// Difficulty : Easy

/* GRAPH CONCEPTUAL SOLUTION - INDEGREE and OUTDEGREE of NODES */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n+1,0), outdegree(n+1,0);
        
        for (auto& edge : trust) { indegree[edge[1]]++; outdegree[edge[0]]++; }
        for (int i=1;i<=n;i++) { if (indegree[i] == n-1 && outdegree[i] == 0) { return i; } }
        
        return -1;
    }
};