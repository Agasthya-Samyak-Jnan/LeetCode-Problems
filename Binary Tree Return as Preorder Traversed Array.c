#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Difficulty: Easy

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder (struct TreeNode* root, int* a, int* i) {
    if (root == NULL) { return; }
    a[*(i)] = root->val;
    *(i) += 1;
    preorder(root->left, a, i); 
    preorder(root->right, a,i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* a = (int*)malloc(100*sizeof(int));
    *(returnSize) = 0;
    preorder(root,a, returnSize);
    return a;
}   