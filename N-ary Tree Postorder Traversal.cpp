#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Difficulty : Easy


// Definition for a Node.
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

/* Recursive Solution */
void post (Node* root,vector<int> &a) {
    if (!root) { return; }
    for(auto node:root->children) {
        post(node,a);
    }
    a.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> a;
        post(root,a);
        return a;
    }
};