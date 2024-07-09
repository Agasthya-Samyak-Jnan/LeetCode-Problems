#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/evaluate-boolean-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
         // If its a Value, return AS IT IS.
         if (root->val == 0 || root->val == 1) { return root->val; }
         // Else , its a OPERATOR. Find its OPERANDS.
         int left = evaluateTree(root->left);
         int right = evaluateTree(root->right);
         // Calculate and Return Result.
         if (root->val == 2) { return left|right; }
         else { return left&right; }
    }
};