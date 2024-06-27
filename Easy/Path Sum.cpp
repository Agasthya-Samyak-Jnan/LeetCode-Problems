#include<bits/stdc++.h>

using namespace std;
// Link to the Problem : https://leetcode.com/problems/path-sum/
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
    int t;
    bool has_path_sum;
    
    void dfs (TreeNode* root, int sum) {
        if (!root) { return; }
        sum += root->val;
        dfs(root->left,sum);
        dfs(root->right,sum);
        if (!root->left && !root->right && sum == t) { has_path_sum  = true; }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
         t = targetSum;
         has_path_sum = false;
         dfs(root,0);
         return has_path_sum;
    }
};