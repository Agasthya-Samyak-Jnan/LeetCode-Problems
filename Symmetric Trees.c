#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Easy

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Solution 1: Single Recursion Way (0ms Runtime)*/
void inorder (struct TreeNode* root, int* a, int*d, int* j, int right) {
    printf("%d ", *j);
    if (root == NULL) { return; }
    inorder(root->left,a,d,j,0);
    a[*j] = root->val; d[*j] = right; *(j) += 1;
    inorder(root->right,a,d,j,1);
}

bool isSymmetric(struct TreeNode* root) {
    
    if(root->left == NULL ^ root->right == NULL) { return false; }
    if(root->left == NULL && root->right == NULL) { return true; }

    int a[600],d[600],i=0,j=0;
    inorder(root,&a,&d,&j,0);
    j--;
    while (i<j) { 
        if (a[i] != a[j] || d[i] == d[j]) { break; } 
        i++; j--;
    }
    if (i >= j) { return true; }
    else { return false; }
}

/* Solution 2: Double Recursion Way (0ms Runtime) */
void inorder (struct TreeNode* root1, struct TreeNode* root2, bool* a) {
    if (root1 == NULL ^ root2 == NULL) { *a = false; return; }
    if (root1 == NULL && root2 == NULL) { return; }
    inorder(root1->left,root2->right,a);
    if (root1->val != root2->val) { *a = false; }
    inorder(root1->right,root2->left,a);   
}

bool isSymmetric (struct TreeNode* root) {
    
     bool* a = true;
     inorder(root,root,&a);
     return a;
}