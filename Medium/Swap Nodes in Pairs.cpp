#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/swap-nodes-in-pairs/
// Difficulty : Medium


struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* Time Complexity: O(N) */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        // Single Node or No Node List Cases
        if (!head || !(head->next)) { return head; }
        
        // Backup Second Node Address as it always will be the HEAD of Modified List 
        struct ListNode* prev = head, *cur = head->next, *temp = cur->next, *backup = head->next;
        
        // Pair Swapping Logic
        while (cur) { 
         cur->next = prev;
         if (temp) { 
             if (temp->next) { prev->next = temp->next; }
             else { prev->next = temp; break; }
         }
         else { prev->next = nullptr; break; } 
         prev = temp;
         cur = temp->next; 
         if (cur) { temp = cur->next; }
        }
        
        // Return the new HEAD (backup address)
        return backup;
    }
};
