#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Difficulty: Medium

using namespace std; 

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    inline ListNode* deleteMiddle(ListNode* head) {
        
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        if (!head || !head->next) { return NULL; }
        
        ListNode* temp = head,*mid = head,*prev;
        
        while (temp != NULL && temp->next != NULL) {
            prev = mid;
            temp = temp->next->next;
            mid = mid->next;
        }
        temp = prev->next;
        prev->next = prev->next->next;
        delete(temp);
        
        return head;
    }
};