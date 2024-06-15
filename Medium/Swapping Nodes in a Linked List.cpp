#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Difficulty: Medium


/* Time Complexity: O(N) = (2N-K) */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    inline ListNode* swapNodes(ListNode* head, int k) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        if (!head || !head->next) { return head; }
        if (!head->next->next) {
            int t = head->val;
            head->val = head->next->val;
            head->next->val = t;
            return head;
        }
        ListNode* temp = head;
        int i = k-1;  
        while (i) {
            temp = temp->next;
            i--;
        }
        ListNode* first = temp;
        i=k;
        while (temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        i = i-k;
        temp = head;

        while (i>0) {
            temp = temp->next;
            i--;
        }
        int t = temp->val;
        temp->val = first->val;
        first->val = t;
        return head; 
    }
};