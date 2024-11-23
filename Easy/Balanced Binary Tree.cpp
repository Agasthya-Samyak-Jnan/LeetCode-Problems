#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/balanced-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH - CHECK RECURSIVELY IF EVERY SUBTREE IS BALANCED. */
class Solution {
public:
    
    int dfs (TreeNode* root) {
        
        if (!root) { return 0; }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        return 1 + max(left,right);
    }
    
    bool isBalanced(TreeNode* root) {
        
        if (!root) { return true; }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
            
        return ((left-1) == right || (right-1) == left || left == right) && isBalanced(root->left) && isBalanced(root->right);  
    }
};