#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Difficulty : Medium

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

/* BREADTH-FIRST SEARCH but you have to seperate each levels as "arrays". */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
       if (root == nullptr) { return {}; }
    
       vector<vector<int>> ans;
       queue<Node*> q;
       q.push(root);
        
       while (!q.empty()) {
           int l_size = q.size();
           vector<int> level;
           for (int i=0;i<l_size;i++) {
               root = q.front(); q.pop();
               level.push_back(root->val);
               for (auto i : root->children) { q.push(i); }
           }
           ans.push_back(level);
       }
       return ans;
    }
};