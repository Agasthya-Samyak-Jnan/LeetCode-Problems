#include<stdio.h>

// Link to the Problem: https://leetcode.com/problems/reverse-linked-list-ii/
// Difficulty: Medium

struct ListNode {
     int val;
     struct ListNode *next;
};
 
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* temp, *prev = NULL;
    
    while (head != NULL) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    } 
    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    //Empty List, Single Node, and Same positions Cases
    if (head == NULL || head->next == NULL) { return head; }
    if (left == right) { return head; }
    if (head->next->next == NULL) { return reverse(head); }
    
    struct ListNode *prev = head, *temp = head, *l = head, *r = head;
    
    // Left - Right Setter
    while (right >= 2) {
     if (left >= 2) { prev = l; l = l->next; left--; }
     r = r->next; right--;
    }
    
    // Limit Reversal to Right
    temp = r->next;
    r->next = NULL;
    
    // Reverse from Left and Link front and back
    if (l != prev) { prev->next = reverse(l); } 
    else { head = reverse(l); }
    l->next = temp; 
    
    return head;
}