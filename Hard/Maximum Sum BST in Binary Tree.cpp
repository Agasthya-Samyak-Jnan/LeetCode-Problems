#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Difficulty : Hard

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH (CAN BE SOLVED BY SIMPLER DEPTH-FIRST SEARCH USING MEMOIZATION BUT EXCEEDS TIME LIMIT) */
class Solution {
public:

    int max_sum = 0;

    // { isBSTvalid, minOfSubtree, maxOfSubtree, subtreeSum }
    vector<int> isBST (TreeNode* root) {
        if (!root) { return {1, INT_MAX, INT_MIN, 0}; }
        auto left = isBST(root->left);
        auto right = isBST(root->right);
        if (left[0] && right[0] && left[2] < root->val && root->val < right[1]) {
            int MIN = min(left[1],root->val);
            int MAX = max(right[2],root->val);
            int sum = left[3] + right[3] + root->val; 
            max_sum = max(max_sum,sum);
            return {1, MIN, MAX, sum}; 
        }
        return {0, INT_MAX, INT_MIN, 0};
    }

    int maxSumBST(TreeNode* root) {
        isBST(root);
        return max_sum;
    }
};