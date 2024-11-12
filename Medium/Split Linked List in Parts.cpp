#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/split-linked-list-in-parts/
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
    int listLength (ListNode* head) {
        
        int n = 0;
        while (head) { n++; head = head->next; }
        
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int n = listLength(head), p = n/k , r = n%k , i = 0, j;
        ListNode* temp = head;
        vector<ListNode*> ans(k,nullptr);
        
        if (p == 0) { p = 1; r = 0; }
        
        while (head && i<k) {
            
            j = p-1;
            if (r) { j += 1; r--; }
            
            ans[i] = head;
            
            while (j) { head = head->next; j--; }
            
            temp = head;
            head = head->next;
            temp->next = nullptr;
            
            i++;
        }
        
        return ans;
    }
};