#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/trim-a-binary-search-tree/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* RECURSIVE SOLUTION */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if (!root) { return nullptr; }
        
        // Check all Nodes in POSTORDER.
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        
        // Current Node is Lesser than 'low'.
        /* Hence connect its Right Subtree to parent because 
           it might contain values greater than 'low'. */
        if (root->val < low) { return root->right; }
        
        // Current Node is Greater than 'high'.
        /* Hence connect its Left Subtree to parent because 
           it might contain values lesser than 'high'. */
        if (root->val > high) { return root->left; }
        
        // Node is within [low,high]. Keep this Node.
        return root;
    }
};