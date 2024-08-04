#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-two-sorted-lists/
// Difficulty : Easy

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* RECURSION USED FOR SIMPLIFIED CODE LOGIC - TC : O(m+n) , SC : O(m+n) */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1 && !list2) { return nullptr; }
        
        if (list1 && !list2) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        
        if (!list1 && list2) { return new ListNode(list2->val,mergeTwoLists(list1,list2->next)); }
        
        if (list1->val < list2->val) { return new ListNode(list1->val,mergeTwoLists(list1->next,list2)); }
        return new ListNode(list2->val,mergeTwoLists(list1,list2->next));
        
    }
};