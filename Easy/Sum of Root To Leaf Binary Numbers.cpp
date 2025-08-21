#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH AND [BIT MANIPULATION OR SIMPLE MATH] */

/* Simple Math Based Solution */
class Solution {
public:

    int dfs (TreeNode* root, int sum) {
        if (!root) { return 0; }
        if (!root->left and !root->right) { return (sum+root->val); }
        return dfs(root->left, (sum+root->val)*2) + dfs(root->right, (sum+root->val)*2);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

class Solution {
public:

    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        if (!root) { return 0; }
        if (!root->left and !root->right) { return (sum+root->val); }
        return sumRootToLeaf(root->left,(sum+root->val)*2) + sumRootToLeaf(root->right,(sum+root->val)*2);
    }
};

/* Bit Manipulation Based Solution - Lesser Memory and Time Usage */
/* Multiply by 2 is same as 1-bit Left Shift Operation. */
/* Adding 1 to a Number is same as ORing a 1-bit to a Number. */
class Solution {
public:

    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        if (!root) { return 0; }
        if (!root->left and !root->right) { return (sum|root->val); }
        return sumRootToLeaf(root->left,(sum|root->val)<<1) + sumRootToLeaf(root->right,(sum|root->val)<<1);
    }
};