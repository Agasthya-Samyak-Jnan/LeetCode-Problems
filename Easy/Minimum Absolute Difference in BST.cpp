#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Difficulty: Easy

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* INORDER TRAVERSAL - DIFFERENCE BETWEEN IMMEDIATE NUMBERS IN SORTED ORDER IS ALWAYS MINIMUM, GLOBAL COMPARISON NOT NEEDED. */
class Solution {
    public:
        int a = -1000000, diff = 1000000;
    
        void inorder (TreeNode* root) {
            if (!root) { return; }
            inorder(root->left);
            diff = min(diff,root->val-a);
            a = root->val;
            inorder(root->right);
        } 
    
        int getMinimumDifference(TreeNode* root) {
            inorder(root);
            return diff;
        }
};