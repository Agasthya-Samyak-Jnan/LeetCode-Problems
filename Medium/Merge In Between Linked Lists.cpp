#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-in-between-linked-lists/
// Difficulty : Medium 

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int i = 0;
        ListNode *t1 = list1, *t2;
        
        while (i < a-1) { t1 = t1->next; i++; }
        
        t2 = t1;
        
        while (i <= b) { t2 = t2->next; i++; }
        
        t1->next = list2;
        
        while (t1->next) { t1 = t1->next; }
        
        t1->next = t2;
        
        return list1;
    }
};