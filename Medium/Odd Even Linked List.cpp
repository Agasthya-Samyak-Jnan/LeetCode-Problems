#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/odd-even-linked-list/
// Difficulty: Medium

using namespace std; 

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// BETTER SOLUTION
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* t = head->next, *s = head, *temp;  
        while (t != NULL && t->next != NULL) {
                temp = t->next;
                t->next = t->next->next;                
                temp->next = s->next;
                s->next = temp;
                s = s->next;
                t = t->next;            
        }       
        return head;
    }
};

// BEST SOLUTION ( -2 Operations per Iteration )
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) { return head; }
        ListNode* _1 = head, *_2 = head->next, *even_connect = _2;
        while (_2 != NULL && _2->next != NULL) {
              _1->next = _2->next;
              _1 = _1->next;
              _2->next = _1->next;
              _2 = _2->next;
        } 
        _1->next = even_connect;
        return head;
    }
};