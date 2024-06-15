#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
//Difficulty: Medium

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* doubleIt(struct ListNode* head){
    
    if (head->val == 0) { return head; }
    
    struct ListNode* p = head, *prev;
    
    while (p != NULL) 
    {
        p->val = p->val*2;
        if (p->val > 9) 
        { 
            if (p == head) 
            {
              prev = (struct ListNode*)malloc(sizeof(struct ListNode));
              prev->val = 0;
              prev->next = p;
              head = prev;
            }
         prev->val++; p->val %= 10; 
        }
        prev = p;
        p = p->next;      
    } 
    return head;
}