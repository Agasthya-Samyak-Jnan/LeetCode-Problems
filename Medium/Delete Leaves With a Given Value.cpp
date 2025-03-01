#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/delete-leaves-with-a-given-value/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH (POST-ORDER) AND PROPOGATION OF VALUES USING RECURSION */
class Solution {
    public:
        TreeNode* removeLeafNodes(TreeNode* root, int target) {
            if (!root) { return nullptr; }
            root->left = removeLeafNodes(root->left,target);
            root->right = removeLeafNodes(root->right,target);
            return (!root->left and !root->right and root->val == target) ? nullptr : root;
        }
};