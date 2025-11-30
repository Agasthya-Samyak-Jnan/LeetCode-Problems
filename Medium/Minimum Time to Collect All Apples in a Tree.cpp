#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Difficulty: Medium

using namespace std;

/* TRAVERSAL OF UNDIRECTED ACYCLIC GRAPHS / N-ARY TREES */

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    vector<bool> hasApple;
    unordered_map<int,vector<int>> g;

    int dfs (int node, int parent) {
        int time = (hasApple[node])*2;
        for (auto child : g[node]) { if (child != parent) { time += dfs(child,node); } }
        return (time > 0 and !hasApple[node]) ? time + 2 : time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        this->hasApple = hasApple;

        for (auto e : edges) { 
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return max(0, dfs(0,-1)-2);
    }
};