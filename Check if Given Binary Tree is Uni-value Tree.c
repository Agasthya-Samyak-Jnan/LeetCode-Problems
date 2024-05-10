#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Link to the Problem: https://leetcode.com/problems/univalued-binary-tree/
//Difficulty: Easy

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
void preorder (struct TreeNode* root, bool* a) {
    if (root == NULL) { return; }
    if((root->left != NULL && root->left->val != root->val) ||  
       (root->right != NULL && root->right->val != root->val)) { *(a) = false; }
    preorder(root->left,a);
    preorder(root->right,a);
}

bool isUnivalTree(struct TreeNode* root) {
    bool a = true;
    preorder(root,&a);
    return a;
}