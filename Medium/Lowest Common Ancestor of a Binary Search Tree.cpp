#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BINARY SEARCH TREE PROPERTY : LEFT IS LESSER THAN ROOT , RIGHT IS GREATER THAN ROOT - BINARY SEARCH LOGIC */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        /* Common Ancestor Cases : Ancestor exists below this node. */
        /* If Both 'p' and 'q' are lesser than current node value,
           Both are on the Left Branch of this node. */
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        /* If Both 'p' and 'q' are greater than current node value,
           Both are on the Right Branch of this node. */
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        
        /* If 'p' and 'q' are on seperate branches , this is the deepest Ancestor of both,
           No ancestor can exist below this node. */
        return root;
        
    }
};