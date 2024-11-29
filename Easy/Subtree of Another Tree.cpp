#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/subtree-of-another-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH BASED SOLUTIONS */

/* 1. DFS SERIALIZATION OF TREES INTO STRINGS */
class Solution {
public:
    string serialize (TreeNode* root) {
        if (!root) { return "#"; }
        return "." + to_string(root->val) + "." + serialize(root->left) + "." + serialize(root->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return serialize(root).find(serialize(subRoot)) != string::npos;
    }
};

/* 2. DIRECT COMPARSION OF ALL POSSIBLE SUBTREES IN GIVEN TREE TO THE GIVEN SUBTREE using DFS */
class Solution {
public:
    
    bool dfs (TreeNode* r1, TreeNode* r2) {
        
        if (!r1 && !r2) { return true; }
        if ((r1 == nullptr ^ r2 == nullptr) || r1->val != r2->val) { return false; }
        
        return dfs(r1->left,r2->left) && dfs(r1->right,r2->right);  
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (!root) { return false; }
        
        return dfs(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};