#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Difficulty : Medium


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity : O(n) = (n/2)+(n/2)+(n/2) = middle detection + half reversal + sum check
class Solution {
public:
    
    inline ListNode* reverse(ListNode* head) {
        ListNode* temp, *prev = NULL;
    
        while (head != NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        } 
        return prev;
    }
    
    inline int pairSum(ListNode* head) {
        
        int sum = 0;
        ListNode *i = head, *j = head->next;
        
        // Set 'i' to middle of list using "slow and fast pointers" method
        while (j->next) {
            i = i->next;
            j = j->next->next;
        }
        
        // Reverse Half List and get head of second half list
        ListNode* head2 = reverse(i);
        
        while (head) {
            int s = head->val + head2->val;
            if (s>sum) { sum = s; }
            head = head->next;
            head2 = head2->next;
        }
        
        return sum;
        
    }
};