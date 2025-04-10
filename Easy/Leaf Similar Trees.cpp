#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/leaf-similar-trees/
// Difficulty : Easy

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
    
        void dfs (TreeNode* root, vector<int>& seq) {
            if (!root) { return; }
            if (!root->left and !root->right) {
                seq.push_back(root->val);
                return;
            }
            dfs(root->left,seq);
            dfs(root->right,seq);
        }
    
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> seq1, seq2;
            dfs(root1,seq1);
            dfs(root2,seq2);
            return (seq1 == seq2);
        }
};