#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Link to the Problem: https://leetcode.com/problems/same-tree/submissions/
//Difficulty: Easy

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

void inorder (struct TreeNode* p, struct TreeNode* q, bool* a) {
    if (p == NULL && q == NULL) { return; }
    if (p == NULL ^ q == NULL) { *a = false; return; }
    inorder(p->left,q->left,a);
    if (p->val != q->val) { *a = false; }
    inorder(p->right,q->right,a);
}


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool a = true;
    inorder(p,q,&a);
    return a;
}