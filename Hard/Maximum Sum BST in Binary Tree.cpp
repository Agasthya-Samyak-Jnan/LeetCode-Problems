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
    vector<int> dfs (TreeNode* root) {
        
        if (!root) { return {1, INT_MAX, INT_MIN, 0, 0}; }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left[0] and right[0] and left[2] < root->val and root->val < right[1]) {
            int MIN = min({left[1],right[1],root->val});
            int MAX = max({left[2],right[2],root->val});
            int sum = left[3] + right[3] + root->val;
            int max_sum = max({left[4],right[4],sum});
            return {1, MIN, MAX, sum, max_sum};
        }

        return {0, INT_MAX, INT_MIN, 0, max(left[4],right[4])};
    }

    int maxSumBST(TreeNode* root) {
        return dfs(root)[4];
    }
};