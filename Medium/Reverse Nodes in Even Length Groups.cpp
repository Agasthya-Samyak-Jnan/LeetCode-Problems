#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
// Difficulty : Medium

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* LINKED LIST - HANDLING POINTERS AND IMPLMETATION INTENSIVE */
class Solution {
public:

    // Linked List Reversing Function (Iterative)
    pair<ListNode*,ListNode*> reverseList (ListNode* head) {

        ListNode* Curr = head, *Prev = nullptr, *Next = Curr->next;

        while (Curr) {
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }

        return {Prev,head}; // New Tail and Head of Reversed Linked List

    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* Head = head, *prev = nullptr;
        int g = 1;

        while (head) {

            ListNode* start = head;
            int n = g;

            while (n>1 and head) {
                head = head->next;
                n--;
            }

            // Group NOT Full Size Case (Always Last Group)
            if (!head) {
                if ((g-n) % 2 == 0) {
                    auto [HEAD,TAIL] = reverseList(start);
                    prev->next = HEAD;
                }
                break;
            }

            // Group Full Size Cases

            // Even Length Group - Reverse the Group
            if (g % 2 == 0) {

                ListNode* end = head;
                head = head->next; 
                end->next = nullptr; // Seperate the Group from Parts of List beyond it to avoid messing whole list beyond the group.

                auto [HEAD,TAIL] = reverseList(start); // Reverse the Group

                prev->next = HEAD; // Join Reversed Group's Backside
                TAIL->next = head; // Join Reversed Group's Frontside
                prev = TAIL; // Pointer pointing to Next Group from outside the next Group (Useful for Linking Reversed Lists).
            }
            // Odd Length Group - Don't Modify
            else if (head) {
                prev = head; // Pointer pointing to Next Group from outside the next Group (Useful for Linking Reversed Lists).
                head = head->next;
            }

            // Move to next Group
            g++;

        }
        
        return Head;
    }
};