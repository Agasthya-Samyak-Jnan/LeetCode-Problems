#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Difficulty : Easy

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/* Hash Map Solution : Time Complexity O(m+n) Space Complexity O(m) */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {    
        ListNode* tempA = headA, *tempB = headB;
        unordered_map <ListNode*,int> A; 
        
        while (tempA) { A[tempA] = 1; tempA = tempA->next; }     
        
        while (tempB) { 
            if ( A[tempB] ) { return tempB; } 
            tempB = tempB->next; 
        }   
        
        return NULL;
        
    }
};

/* Best Solution : Time Complexity O(m+n) Space Complexity O(1) */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        if(headA == NULL || headB == NULL) return NULL;
        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
            if(tempA == tempB) return tempA;
            if(tempA == NULL) tempA = headB;
            if(tempB == NULL) tempB = headA;
        }
        return tempA;
    }
};

/* Special Solution that works by modifying Linked Lists - NOT accepted but works */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempA = headA, *tempB = headB,*temp;
        
        while (tempA || tempB) {
            if (tempA && tempA->next == tempA) { return tempA; }
            if (tempB && tempB->next == tempB) { return tempB; }
            if (tempA) { temp = tempA; tempA = tempA->next; temp->next = temp; }
            if (tempB) { temp = tempB; tempB = tempB->next; temp->next = temp; }
        }
        return NULL;
    }
};
