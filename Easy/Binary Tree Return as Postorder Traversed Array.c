#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Difficulty: Easy

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

void postorder (struct TreeNode* root, int* a, int* i) {
    if (root == NULL) { return; }
    postorder(root->left, a, i);
    postorder(root->right, a,i);
    a[*(i)] = root->val; 
    *(i) += 1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* a = (int*)malloc(100*sizeof(int));
    *(returnSize) = 0;
    postorder(root,a, returnSize);
    return a;
}