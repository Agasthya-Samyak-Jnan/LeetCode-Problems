#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
// Difficulty : Medium 


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/* Solution That Actually Cares for MEMORY MANAGEMENT AND DELETES NODES - CLEAN DELETION */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> set(nums.begin(),nums.end());
        
        ListNode* temp = head, *prev = temp;
        
        while (temp) {
            if (temp == head && set.count(temp->val)) {
                temp = temp->next;
                delete head;
                head = temp;
            }
            else if (set.count(temp->val)) {
                 prev->next = temp->next;
                 delete temp;
                 temp = prev->next;
            }
            else { prev = temp; temp = temp->next; }
        }
        
        return head;        
    }
};

/* OPTIMISED SOLUTION - MODIFIES LIST ARRANGEMENT BUT DOES NOT ACTUALLY DELETE THE NODES - DIRTY DELETION */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        unordered_set<int> set(nums.begin(),nums.end());
        
        ListNode* temp = head, *newhead = nullptr, *newtemp = nullptr;
        
        while (!newhead) {
            if (!set.count(temp->val)) { newhead = temp; newtemp = newhead; }
            temp = temp->next;
        }
        
        while (temp) {
            if (!set.count(temp->val)) { newtemp->next = temp; newtemp = newtemp->next; }
            temp = temp->next;
        }
        
        newtemp->next = nullptr;
        
        return newhead;        
    }
};