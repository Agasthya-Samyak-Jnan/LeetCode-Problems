#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-the-number-of-good-nodes/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH on N-ary Undirected Tree */
class Solution {
public:
    vector<vector<int>> g;
    int good_nodes = 0;

    int dfs (int node, int parent) {

        int prev_size = -1, curr_size = -1, total_size = 1;
        bool good = true;

        for (auto child : g[node]) {
            if (child != parent) {
                curr_size = dfs(child, node);
                total_size += curr_size;
                if (prev_size != -1 and curr_size != prev_size) { good = false; } 
                prev_size = curr_size;
            }
        }  

        good_nodes += good;

        return total_size;
    }

    int countGoodNodes(vector<vector<int>>& edges) {

        int n = edges.size();
        g = vector<vector<int>>(n+1);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0,-1);

        return good_nodes;
    }
};