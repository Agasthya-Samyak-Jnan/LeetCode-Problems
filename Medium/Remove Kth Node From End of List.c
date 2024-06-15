#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Difficulty: Medium

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) { return head; }
    
    int count = 1;
    struct ListNode* temp = head, *temp2;
    while (temp->next != NULL) { temp = temp->next; count++; }
    
    count = count - n + 1;
    temp = head;
    
    while (count > 2) {
        temp = temp->next;
        count--;
    }
    
    if (temp->next == NULL || count == 1) {
        temp = head->next; 
        free(head); 
        return temp; 
    }
    
    
    else { 
        temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    
    return head;
    
}