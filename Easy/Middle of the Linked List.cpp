#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/middle-of-the-linked-list/
// Difficulty : Easy

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* middle = head;
        while (head && head->next) { head = head->next->next; middle = middle->next; }
        return middle;             
    }
};