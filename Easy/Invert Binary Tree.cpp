#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/invert-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (!root) { return nullptr; }
        TreeNode* temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
        
    }
};

class Solution {
public:
    void dfs (TreeNode* root) {       
        if (!root) { return; }
        swap(root->left,root->right);
        dfs(root->left);
        dfs(root->right);       
    }
    
    TreeNode* invertTree(TreeNode* root) {       
        dfs(root);
        return root;        
    }
};