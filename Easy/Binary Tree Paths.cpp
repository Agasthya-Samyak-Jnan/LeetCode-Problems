#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-paths/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH  + BACKTRACKING THE PATH WE GO DOWN EACH TIME */
class Solution {
public:
    vector<string> ans;
    
    void dfs (TreeNode* root,string temp) {
        if (!root->left && !root->right) { ans.push_back(temp); }
        if (root->left) { dfs(root->left,temp + "->" + to_string(root->left->val)); }
        if (root->right) { dfs(root->right,temp + "->" + to_string(root->right->val)); }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,to_string(root->val));
        return ans;
    }
};



