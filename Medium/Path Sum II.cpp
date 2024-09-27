#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/path-sum-ii/
// Difficulty : Medium

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH WITH BACKTRACKING ARRAY */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int t;
    
    void dfs (TreeNode* root, int sum) {
        
        temp.push_back(root->val);
        
        if (!root->left && !root->right && sum == t) { ans.push_back(temp); }
        if (root->left) { dfs(root->left,sum + root->left->val); }
        if (root->right) { dfs(root->right,sum + root->right->val); }
        
        temp.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        if (!root) { return {}; }
        dfs(root,root->val);
        return ans;
    }
};