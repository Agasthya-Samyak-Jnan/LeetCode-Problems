#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-tilt/
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
    int tilt = 0;

    int dfs (TreeNode* root) {
        if(!root) { return 0; }
        int left = dfs(root->left), right = dfs(root->right);
        tilt += abs(left-right);
        return left + root->val + right;
    }

    int findTilt(TreeNode* root) {
        dfs(root);
        return tilt;
    }
};