#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* INORDER DEPTH-FIRST SEARCH SINCE BINARY SEARCH TREE IS SORTED INORDER-WISE */
class Solution {
public:

    int diff = 100000, prev = -100000;

    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        diff = min(diff, root->val - prev);
        prev = root->val;
        inorder(root->right); 
    }


    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return diff;
    }
};
