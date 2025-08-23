#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    long long MIN2nd = LLONG_MAX;

    void dfs (TreeNode* root) {
        if (!root->left) { return; }
        if (root->left->val == root->val) { dfs(root->left); }
        else { MIN2nd = min(MIN2nd, (long long)root->left->val); }
        if (root->right->val == root->val) { dfs(root->right); }
        else { MIN2nd = min(MIN2nd, (long long)root->right->val); }
    }

    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return MIN2nd == LLONG_MAX ? -1 : MIN2nd;
    }
};