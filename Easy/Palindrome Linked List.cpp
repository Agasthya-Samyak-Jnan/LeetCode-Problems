#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/palindrome-linked-list/
// Difficulty : Easy

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Time Complexity : O(N) = (3*(N/2)) , Space Complexity : O(1) = (Few Pointers) */
class Solution {
public:
    // Helper Function to Reverse List
    ListNode* reverse (ListNode* head) {
        ListNode* temp, *prev = NULL;
        while (head != NULL) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        } 
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
         
         if (!head->next) { return head; }
        
         ListNode* temp = head->next, *mid = head;
         
        // Find Middle of List (n/2) using Fast and Slow Pointer Method
         while (temp && temp->next) { temp = temp->next->next; mid = mid->next; }
         
        // Reverse Half List (n/2) using  iterative Reversal 
        mid = reverse(mid->next);
                               
        // Compare  Two Halves of List if they are same or not (n/2) 
        while (mid != nullptr) {
            if (mid->val != head->val) { return false; }
            mid = mid->next;
            head = head->next;
        }
        return true;        
    }
};