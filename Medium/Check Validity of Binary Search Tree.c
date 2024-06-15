#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Link to the Problem: https://leetcode.com/problems/validate-binary-search-tree/
//Difficulty: Medium

//Hint: Traverse Iteratively using Stack

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
struct node {
    struct TreeNode* t;
    struct node* next; 
};

void push (struct node** s, struct TreeNode* a) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->t = a;
    temp->next = *s;
    *s = temp;
}

struct TreeNode* pop (struct node** s) {
    struct TreeNode* temp = (*s)->t;
    struct node* top = *s;
    *s = top->next;
    free(top);
    return temp;
}


bool isValidBST(struct TreeNode* root) {
    
    struct TreeNode* current = root;
    long int prev = -2147483650;

    struct node* s = NULL;
    
    while (1) {
        if (current != NULL) {
            push(&s,current);
            current = current->left;
        }
        
        else {
            if (s != NULL) {
                current = pop(&s);
                if (current->val <= prev) { return false; }
                prev = current->val;
                current = current->right; 
            }
            else { return true; }
        }
    }  
    return true;
}