#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Difficulty : Hard

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* LINKED LIST + RECURSION OR ITERATION */

/* RECURSION FOR REVERSAL OF EACH GROUP - ITERATION TO FIND EACH GROUP - ITERATE AND THEN DO RECURSION FOR REVERSAL */
class Solution {
    public:
        ListNode* reverseList (ListNode* head, int k) {
    
            if (!head or !head->next or k == 1) { return head; }
    
            ListNode* newHead = reverseList(head->next,k-1);
            head->next->next = head;
            head->next = nullptr;
    
            return newHead;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
    
            if (!head and !head->next) { return head; }
            
            int n = k;
            ListNode* start = head, *root;
            while (n and head) {
                head = head->next;
                n--;
            }
            root = reverseList(start,k);
            start->next = head;
            
            while (head) {
                    n = k;
                    start->next = head;
                    while (n and head) {
                        head = head->next;
                        n--;
                    }
                    if (n) { break; }
                    ListNode* prev = start->next;
                    start->next = reverseList(start->next,k);
                    start = prev;
                    
            }
    
            return root;
        }
};

/* NESTED RECURSION - RECURSIVELY REVERSE EACH GROUP AND THEN CONNECT EACH GROUP AFTER REVERSAL RECURSIVELY */
class Solution {
    public:
        ListNode* reverseList (ListNode* head, int k) {
    
            if (!head or !head->next or k == 1) { return head; }
    
            ListNode* newHead = reverseList(head->next,k-1);
            head->next->next = head;
            head->next = nullptr;
    
            return newHead;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
    
            if (!head or !head->next) { return head; }
            
            int n = k;
            ListNode* prev_start = head, *root;
            while (n and head) {
                head = head->next;
                n--;
            }
    
            if (n != 0) { return prev_start; }
    
            ListNode* nextHead = reverseKGroup(head,k);
            ListNode* newHead = reverseList(prev_start,k);
            prev_start->next = nextHead;
            return newHead;
        }
};