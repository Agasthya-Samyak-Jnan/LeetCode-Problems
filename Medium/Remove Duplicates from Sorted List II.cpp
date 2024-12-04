#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* TWO POINTERS AND EXTRA NODE USAGE */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* extra = new ListNode(1000,head);
        ListNode* i = head, *j = head, *prev = extra;
        
        while (i && i->next) {
            if (i->val != i->next->val) { prev = i; i = i->next; }
            else {
                j = i;
                while (j && j->val == i->val) { j = j->next; }
                prev->next = j;
                i = j;
            }
        }
        
        return extra->next;
    }
};