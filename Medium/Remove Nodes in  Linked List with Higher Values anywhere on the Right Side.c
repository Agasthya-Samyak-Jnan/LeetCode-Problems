#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/remove-nodes-from-linked-list/
//Difficulty: Medium

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* s = NULL ;

struct ListNode* pop () {
    struct ListNode* temp = s;
    s = s->next;
    return temp;
}

void push (struct ListNode* p) {
    p->next = s;
    s = p;
}

struct ListNode* removeNodes(struct ListNode* head) {
    
    struct ListNode* temp = head,*prev = NULL; int max=0;
    
    // Load the List to Stack
    while (temp != NULL) {
        temp = temp->next;
        push (head);
        if (head->val > max) { max = head->val; }
        head = temp;
    }
    head = pop(); temp = head;
    
    // Unload the Required Nodes into List from Stack
    while ( s != NULL ) 
    {   
        if (temp->val <= s->val) { temp->next = s; temp = temp->next; pop(); }
        else { pop(); }
    }
    temp->next = NULL;
    
    while (head != NULL) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
      
    return prev;
    
}

int main () {

    struct ListNode a5 = {8,NULL}; 
    struct ListNode a4 = {4,&a5}; 
    struct ListNode a3 = {13,&a4};
    struct ListNode a2 = {2,&a3};
    struct ListNode a1 = {5,&a2};
    
    display(&a1);
    struct ListNode* new = removeNodes(&a1);
    display(new);

    return 0;
}