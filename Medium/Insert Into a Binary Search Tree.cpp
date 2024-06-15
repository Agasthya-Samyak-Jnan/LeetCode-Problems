#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Difficulty: Medium


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/* Iterative Solution */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
      TreeNode* prev = root, *n = new TreeNode(val);
      if (root == NULL) { return n; }
      TreeNode* preserved_root = root;
      while (root != NULL) {
        prev = root;
        if (val >= root->val) { root = root->right; }
        else { root = root->left; }
      }
      if (val >= prev->val) { prev->right = n; }
      else { prev->left = n; }
      return preserved_root;
    }
};

/* Recursive Solution */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* n = new TreeNode(val);
            return n;
        }
        if (val >= root->val) { root->right = insertIntoBST(root->right,val); }
        else { root->left = insertIntoBST(root->left,val); }
        return root;
    }
};