#include<bits/stdc++.h>

using namespace std;
 
// Link to the Problem : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH + MONOTONIC STACK (DECREASING UPWARDS) */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]), *curr;
        int i = 1, n = preorder.size();
        
        s.push(root);
        
        while (!s.empty() && i<n) {
            
            curr = s.top();
            // Monotonic Stack - Always Decreasing Upwards
            while (!s.empty() && s.top()->val < preorder[i]) { curr = s.top(); s.pop(); }
            
            // BST Property - Lesser on Left , Greater on Right
            if (preorder[i] < curr->val) { 
                curr->left = new TreeNode(preorder[i++]); 
                s.push(curr->left);
            }
            else { 
                curr->right = new TreeNode(preorder[i++]); 
                s.push(curr->right);
            }
            
        }
        
        return root;
    }
};