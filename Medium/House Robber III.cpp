#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/house-robber-iii/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* RECURSION - DEPTH-FIRST SEARCH - TIME LIMIT EXCEEDED */
class Solution {
    public:
    
        int solve (TreeNode* root, bool can_rob) {
    
            if (!root) { return 0; }
    
            if (can_rob) { 
                return root->val + solve(root->left,0) + solve(root->right,0); 
            }
    
            int left = max(solve(root->left,1),solve(root->left,0));
            int right = max(solve(root->right,1),solve(root->right,0));
    
            return left + right;
        }
    
        int rob(TreeNode* root) {
            return max(solve(root,0),solve(root,1));
        }
};

/* RECURSION WITH MEMOISATION - 2D MEMOISATION */
class Solution {
    public:
        unordered_map<TreeNode*,unordered_map<int,int>> dp;
    
        int solve (TreeNode* root, bool can_rob) {
    
            if (!root) { return 0; }
    
            if (dp[root].find(can_rob) != dp[root].end()) { return dp[root][can_rob]; }
    
            if (can_rob) { 
                dp[root][can_rob] = root->val + solve(root->left,0) + solve(root->right,0); // Left - Don't Rob and Right - Don't Rob
            }
            else {
                dp[root][can_rob] = max(solve(root->left,1),solve(root->left,0)); // Left - Rob or Don't Rob
                dp[root][can_rob] += max(solve(root->right,1),solve(root->right,0)); // Right - Rob or Don't Rob
            }
    
            return dp[root][can_rob];
        }
    
        int rob(TreeNode* root) {
            return max(solve(root,0),solve(root,1));
        }
};