#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        
        if (!head || !head->next) { return head; }
        
        ListNode* temp = head; vector<int> list;
        while (temp) { list.push_back(temp->val); temp = temp->next; }
        sort(list.begin(),list.end());
        int n = list.size(); temp = head; 
        for (int i=0;i<n;i++) { temp->val = list[i]; temp = temp->next; }
        
        return head;
    }
};