#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/linked-list-cycle-ii/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/* Hash Table Solution */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map <ListNode*,int> mp;
        while (head) {
            if (mp[head]) { return head; }  
            mp[head] = 1;
            head = head->next;
        }
        return nullptr; 
    }
};

/* Two Pointer Method - Slow and Fast Traversing Pointers */
class Solution {
public:
    inline ListNode *detectCycle(ListNode *head) {
        
        if (!head || !head->next) { return nullptr; }
        
        ListNode*x1 = head,*x2 = head;
        
        while (x2 && x2->next) {
            
            x1 = x1->next;
            x2 = x2->next->next;
            
            if (x1 == x2) {
                x2 = head;
                while (x1 != x2) {
                    x2 = x2->next;
                    x1 = x1->next;
                }
                return x2;
            }
        }
        return nullptr;
    }
};