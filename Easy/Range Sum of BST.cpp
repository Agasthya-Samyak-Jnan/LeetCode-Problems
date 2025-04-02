#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-sum-of-bst/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH - INORDER TRAVERSAL */
class Solution {
    public:
    
        int sum = 0, high, low;
    
        void inorder (TreeNode* root) {
            if (!root) { return; }
            inorder(root->left);
            if (root->val >= low and root->val <= high) { sum += root->val; }
            inorder(root->right);
        }
    
        int rangeSumBST(TreeNode* root, int low, int high) {
            this->low = low;
            this->high = high;
            inorder(root);
            return sum;
        }
};