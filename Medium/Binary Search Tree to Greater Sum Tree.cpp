#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DEPTH-FIRST SERACH - INORDER TRAVERSAL BUT REVERSED (Right->Root->Left)
class Solution {
public:
    int sum = 0;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->right);
        sum += root->val;
        root->val = sum;
        inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
};