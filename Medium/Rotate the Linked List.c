#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/rotate-list/
//Difficulty: Medium

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* rotateRight(struct ListNode* head, int n) {
    if (head == NULL) { return head; }
    
    int count = 1;
    struct ListNode* temp = head, *temp2;
    
    while (temp->next != NULL) { temp = temp->next; count++; }
    temp->next = head;
    
    count = count - (n%count) + 1;
    temp = head;
    
    while (count > 2) {
        temp = temp->next;
        count--;
    }
    
    head = temp->next;
    temp->next = NULL;
    
    return head;
    
}