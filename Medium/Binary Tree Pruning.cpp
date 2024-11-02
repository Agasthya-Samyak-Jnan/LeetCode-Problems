#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-pruning/
// Difficulty : Medium

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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) { return nullptr; }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return (root->val == 1 || root->left || root->right) ? root : nullptr;
    }
};