#include<bits/stdc++.h>

using namespace std;
// Link to the Problem : https://leetcode.com/problems/longest-univalue-path/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Depth-First-Search Solution */
class Solution {
public:
    int longest_path;
    
    int dfs (TreeNode* root) {
        
        if (!root) { return 0; }
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        int p_left = 0, p_right = 0;
        if (root->left && root->left->val == root->val) { p_left += left+1; }
        if (root->right && root->right->val == root->val) { p_right += right+1; }   
        
        longest_path = max(longest_path,p_left+p_right);
        return max(p_left,p_right);
                     
    }
    
    int longestUnivaluePath(TreeNode* root) {
        longest_path = 0;
        dfs(root);
        return longest_path;
    }
};