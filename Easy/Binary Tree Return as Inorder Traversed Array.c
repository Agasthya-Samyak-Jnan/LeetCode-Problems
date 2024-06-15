#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty: Easy

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder (struct TreeNode* root, int* a, int* i) {
    if (root == NULL) { return; }
    inorder(root->left, a, i);
    a[*(i)] = root->val; *(i) += 1; printf("%d ", root->val);
    inorder(root->right, a,i);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    int* a = (int*)malloc(100*sizeof(int));
    *(returnSize) = 0;
    
    inorder(root,a, returnSize);


    return a;
    
}