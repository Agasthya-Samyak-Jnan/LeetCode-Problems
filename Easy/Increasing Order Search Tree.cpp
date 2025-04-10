#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/increasing-order-search-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* STACK + IN-ORDER TRAVERSAL OF BINARY SEARCH TREE */
class Solution {
    public:
        stack<TreeNode*> s;
    
        void inorder (TreeNode* root) {
            if (!root) { return; }
            inorder(root->left);
            s.push(root);
            inorder(root->right);
            root->left = root->right = nullptr;
        }
    
        TreeNode* increasingBST(TreeNode* root) {
    
            inorder(root);
            
            while (!s.empty()) {
                root = s.top(); s.pop();
                if (!s.empty()) { s.top()->right = root; }
            } 
    
            return root;
        }
};