#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// Difficulty : Medium 

/* DEPTH-FIRST SEARCH */

/* Simulation : Do it exactly the way they told - TIME LIMIT EXCEEDED */
class Solution {
public:
    string labels;
    vector<int> count;
    vector<vector<int>> g;

    int dfs1 (int curr, int node, int parent) {
        int c = (labels[curr] == labels[node]);
        for (auto child : g[curr]) {
            if (child != parent) { c += dfs1(child,node,curr); } 
        }
        return c;
    }

    void dfs2 (int curr, int parent) {
        count[curr] = dfs1(curr,curr,parent);
        for (auto child : g[curr]) {
            if (parent != child) { dfs2(child,curr); }
        }
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        this->labels = labels;
        count = vector<int>(n,0);
        g = vector<vector<int>>(n);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs2(0,-1);

        return count;
    }
};

/* 
    Optimized : Find count of each label present in each node's subtree,
                then using node-to-label mapping from 'labels' string,
                count of nodes with same label in its subtree is total number/count of label of that node in all its children subtrees.
*/
class Solution {
public:
    int n;
    string labels;
    vector<int> count;
    vector<vector<int>> g;

    vector<int> dfs (int node, int parent) {

        vector<int> c(26,0);
        c[labels[node]-'a'] = 1;

        for (auto child : g[node]) {
            if (child != parent) {
                auto cc = dfs(child,node);
                for (int i=0;i<26;i++) { c[i] += cc[i]; }
            }
        }

        count[node] = c[labels[node]-'a'];

        return c;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        this->n = n;
        this->labels = labels;
        count = vector<int>(n,0);
        g = vector<vector<int>>(n);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0,-1);
        
        return count;
    }
};