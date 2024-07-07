#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// DIfficulty : Easy 


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/* Depth-First-Search Solution */
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) { return 0; }
        int sum = 0;
        for (auto i : root->children) { sum = max(sum,maxDepth(i)); }
        return 1 + sum;
    }
};