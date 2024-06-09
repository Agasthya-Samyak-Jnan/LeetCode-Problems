#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/remove-linked-list-elements/
// Difficulty: Easy

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
       if (!head) { return NULL; }
       head->next = removeElements(head->next,val);
       return head->val==val?head->next:head;
    }
};