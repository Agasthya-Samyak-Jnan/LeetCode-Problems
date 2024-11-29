#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-left-leaves/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) { return 0; }
        int sum = 0;
        if (root->left && (!root->left->left && !root->left->right)) { sum = root->left->val; }
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
};