#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-sum-iii/
// Difficulty : Medium

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

    long long dfs (TreeNode* root, long long sum, int target) {
        if (!root) { return 0; }
        return (sum + root->val == target) 
            + dfs(root->left,sum + root->val,target) 
            + dfs(root->right,sum + root->val,target);
    }
    
    long long pathSum(TreeNode* root, int target) {
        if (!root) { return 0; }
        return dfs(root,0,target) + pathSum(root->left,target) + pathSum(root->right,target);
    }
};