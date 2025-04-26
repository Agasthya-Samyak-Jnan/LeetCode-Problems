#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH - O(N) SPACE */
class Solution {
public:
    /* To store ADDRESSES of all nodes in PREORDER arrangement */
    vector<TreeNode*> tree;
    
    /* Preorder Traversal and Store all node addresses */
    void preorder (TreeNode* root) {
        if (!root) { return; }
        tree.push_back(root);
        preorder(root->left);
        preorder(root->right);     
    }
    
    void flatten(TreeNode* root) {
        
         if (!root) { return; }
        
         preorder(root);
         int n = tree.size();
        
         /* Rearrange All to Linked List as Described in Question */
         for (int i=0;i<n-1;i++) {
             tree[i]->left = nullptr;
             tree[i]->right = tree[i+1];
         }
        
         tree[n-1]->left = nullptr;
         tree[n-1]->right = nullptr;
        
    }
};

/* ULTIZING TREE STRUCTURE OF ANSWER FORMAT FOR SOLUTION - O(1) SPACE */
class Solution {
    public:
        void flatten(TreeNode* root) {
    
            TreeNode* temp, *part;
    
            while (root) {
                if (root->left) {
                    part = root->right;
                    root->right = root->left;
                    root->left = nullptr;
                    temp = root->right;
                    while (temp->right) { temp = temp->right; }
                    temp->right = part;
                }
                root = root->right;
            }
            
        }
};