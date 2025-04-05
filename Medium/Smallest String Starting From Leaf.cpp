#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/smallest-string-starting-from-leaf/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BACKTRACKING + STRING COMPARISON */
class Solution {
    public:
        string smallest, curr;
    
        Solution() {
            smallest = string(8500, 'z');
            curr = "";
        }
    
        void dfs (TreeNode* root) {
            if (!root) { return; }
    
            string temp = curr;
            curr = (char)('a'+root->val) + curr;
    
            dfs(root->left);
            dfs(root->right);
    
            if (!root->left and !root->right) { smallest = min(smallest,curr); }
    
            curr = temp;
        }
    
        string smallestFromLeaf(TreeNode* root) {
            dfs(root);
            return smallest;
        }
};