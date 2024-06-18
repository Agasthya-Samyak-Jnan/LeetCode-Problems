#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/linked-list-cycle/
// Difficulty : Easy

/* Two Pointers - 1x and 2x Pointers (Nx Pointer) - Every Number is a Multiple of 1. Any Number can be Reached Using 1. */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    inline bool hasCycle(ListNode *head) {
         ListNode *i=head,*j=head; 
         while (j && j->next && i) {
             i = i->next;           // 1x Speed Traversal.
             j = j->next->next;     // 2x Speed Traversal.
             if (!j) { return false; } // if cycle not present, it will end in nullptr.
             if(i == j) { return true; } // If there is a cycle, 1x pointer will eventually                                          // reach one of nodes that 2x pointer visits.                          
         }
         return false;
    }
};