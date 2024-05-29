#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Difficulty: Easy


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/* Recursive Solution */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) { return NULL; }
        if (val < root->val) { return searchBST(root->left,val); }
        else if (root->val == val) { return root; }
        else { return searchBST(root->right,val); }
    }
};

/* Iterative Solution */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
        if (val < root->val) { root = root->left; }
        else if (root->val == val) { return root; }
        else { root = root->right; }
        }
        return NULL;
    }
};