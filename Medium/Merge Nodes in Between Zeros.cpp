#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Difficulty : Medium


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Time Complexity : O(N) , Space Complexity : O(1) */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* i = head, *j = head->next, *prev = head;
        int sum = 0;
        
        while (j) {
            if (j->val != 0) {    
                sum += j->val;
                j = j->next;
            }
            else {
                i->val = sum;
                sum = 0;
                if (j->next) { i = i->next; } 
                else { /*prev = i->next;*/ i->next = nullptr; break; }
                j = j->next;
            }         
        }
        
        /* IF YOU WANT TO DELETE UNNECESSARY NODES FROM MEMORY */
        // i = prev;
        // while (i) {
        //     prev = i;
        //     i = i->next;
        //     delete prev;
        // }
        
        return head;
    }
};