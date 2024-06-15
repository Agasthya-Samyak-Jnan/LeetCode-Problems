#include<stdio.h>
#include<stdlib.h>

/* Sample Testcase 
Input  = [9,9,9,9,9,9,9]
         [9,9,9,9]
Ouptut = [8,9,9,9,0,0,0,1]
*/

//Link to the Problem: https://leetcode.com/problems/add-two-numbers/
//Difficulty: Medium

  struct ListNode {
     int val;
     struct ListNode *next;
  };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* t1 = l1,*t2 = l2; int i=1, j=1;
  
          while (t1->next != NULL) { t1 = t1->next; i++; }
          while (t2->next != NULL) { t2 = t2->next; j++; }  
          
          t1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          t2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          t1->next->next = t2->next->next = NULL; 
          t1->next->val = t2->next->val = 0;
         
          if (i > j) { t1 = l1; t2 = l2; }
          else { t1 = l2; t2 = l1; }
    
          l1 = t1;
          
          while (t1->next != NULL) 
          {   
              l2 = t1;
              if (t1->val + t2->val > 9) {t1->next->val += 1; }
              t1->val = (t1->val + t2->val)%10 ;
              
              t1 = t1->next;
              if (t2->next != NULL) { t2 = t2->next; }
              else { t2->val = 0; }
          }
    if (t1->val == 0) { l2->next = NULL; }
    return l1;
}