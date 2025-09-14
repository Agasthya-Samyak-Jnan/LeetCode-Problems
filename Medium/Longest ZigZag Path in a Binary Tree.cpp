#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DYNMAIC PROGRAMMING  = COMBO OF DEPTH-FIRST SEARCH AND COMMON SENSE. */

/*  PURE RECURSION - TIME LIMIT EXCEEDED */
class Solution {
public:

    int dfs(TreeNode* root, int direction) {
        if (!root) { return 0; }
        return 1 + ((direction == 0) ? dfs(root->left,1) : dfs(root->right,0)); 
    }

    int longestZigZag(TreeNode* root) {
        if (!root) { return 0; }
        int Currpath = max(dfs(root->left,1),dfs(root->right,0));
        int Nextpath = max(longestZigZag(root->left),longestZigZag(root->right));
        return max(Currpath,Nextpath);
    }
};

/* RECURSION + 1D MEMOIZATION (NODE AS DP TABLE KEY) */ 
class Solution {
public:
    unordered_map<TreeNode*,int> dp;

    int dfs(TreeNode* root, int direction) {
        if (!root) { return 0; }
        if (dp.find(root) != dp.end()) { return dp[root]; }
        return dp[root] = 1 + ((direction == 0) ? dfs(root->left,1) : dfs(root->right,0)); 
    }

    int longestZigZag(TreeNode* root) {
        if (!root) { return 0; }
        int Currpath = max(dfs(root->left,1),dfs(root->right,0));
        int Nextpath = max(longestZigZag(root->left),longestZigZag(root->right));
        return max(Currpath,Nextpath);
    }
};