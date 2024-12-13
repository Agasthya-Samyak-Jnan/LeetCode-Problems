#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//Difficulty: Easy

//Time Complexity: O(N)
//Space Complexity: O(1)

struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head) {
      struct ListNode* temp = head;
      if (head == NULL) { return head; }
      while (temp->next != NULL) {
          if(temp->val == temp->next->val) { *(temp) = *(temp->next); }
          else { temp = temp->next; }
      }
    return head;
}

/* PYTHON3 VERSION 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        temp = head
        
        while temp and temp.next :
            while temp.next and temp.next.val == temp.val:
                temp.next = temp.next.next
            temp = temp.next
            
        return head
*/