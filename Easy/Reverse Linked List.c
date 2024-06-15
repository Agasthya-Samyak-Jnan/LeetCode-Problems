#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/reverse-linked-list/
//Difficulty: Easy

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp, *prev = NULL;
    
    while (head != NULL) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    } 
    return prev;
}