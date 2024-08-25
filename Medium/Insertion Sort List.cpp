#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insertion-sort-list/
// Difficulty : Medium

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* THE ACTUAL TRUE IDEA OF INSERTION SORT */
/* DRY RUN IS NEEDED TO UNDERSTAND. */

/* Solution 1 */
    ListNode* insertionSortList(ListNode* head) {
        
        if (!head || !head->next) { return head; }
        
        ListNode* i = head->next, *prev = head,* j,*t = new ListNode(0,head); // Dummy Node to Simplify Code
        
        while (i) {
            
            ListNode* temp = t;
            bool inserted = false;
            // You will reach the Same Node if it greatest if all. Stop when you reach itself and DONT INSERT IT AGAIN.
            while (temp != i) {
                // Insert at Start or Middle anywhere or End.
                if (temp->next && i->val < temp->next->val) { 
                    j = i->next;
                    prev->next = i->next;
                    i->next = temp->next;
                    temp->next = i;
                    i = j;
                    inserted = true;
                    break;
                }
                // Move to compare with each element.
                temp = temp->next;
            }
            
            // If Not Inserted Anywhere Move Ahead one step Normally.
            // Otherwise, move to next of previous node.
            if (!inserted) { prev = i; i = i->next; }
            else { i = prev->next; }
            
        }
        
        return t->next;
    }

/* Solution 2 */
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* newhead = nullptr;
        
        if (!head || !head->next) { return head; }
        
        while (head) {
            
            ListNode* curr = head; // Storing the current node to go ahead early.
            head = head->next;     // This Goes Ahead to Next Node Early , So no worries of disconnection of List.
            
            // If current element is smallest element of all in current sorted list.
            // Insertion at Start.
            if (!newhead || curr->val <= newhead->val) {
                curr->next = newhead;
                newhead = curr; 
            }
            
            // Insertion at Middle/End.
            else {       
                ListNode* temp = newhead;
                while (temp->next && temp->next->val < curr->val) {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }    
        }
        
        return newhead;
    }
