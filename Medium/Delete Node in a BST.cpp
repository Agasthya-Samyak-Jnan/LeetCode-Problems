#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/delete-node-in-a-bst/
// Difficulty: Medium


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* Time Complexity: O(log(N))/O(N)(Skewed Tree) , Space Complexity: O(1) */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
    TreeNode* prev = root, *preserved_Root = root;

    if (root == NULL) { return NULL; }

    if (root->val == key) { 
        if (root->right != NULL) { preserved_Root = root->right; }
        else { preserved_Root = root->left; }
     }

    while (root != NULL && root->val != key) {
        if (key >= root->val) { prev = root; root = root->right; }
        else { prev = root; root = root->left; }
    }

    if (root == NULL) { return preserved_Root; }

    else if (root->left == NULL || root->right == NULL) {
        if (root->right != NULL) 
        { 
         if (root->val >= prev->val) { prev->right = root->right; }
         else { prev->left = root->right; }
        }
        else 
        {
         if (root->val >= prev->val) { prev->right = root->left; }
         else { prev->left = root->left; }
        }
        delete(root);
    }

    else {
        if (root->val >= prev->val) { prev->right = root->right; prev = prev->right; }
        else { prev->left = root->right; prev = prev->left; }
        
        while ( prev->left != NULL) { prev = prev->left; }
        prev->left = root->left;
        delete(root);
    }
    
    return preserved_Root;
    }
};