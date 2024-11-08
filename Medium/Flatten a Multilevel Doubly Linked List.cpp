#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
// Difficulty : Medium 

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

/* DEPTH-FIRST SEARCH AND FLOW OF VALUES IN RECURSIVE FUNCTION CALL STACK */
class Solution {
public:
    Node* flatten(Node* head) {
        
        if (!head) { return nullptr; }
        
        Node* start_node = head;
        
        // If this has child List.
        if (head->child) {
            
            // Keep address of next node to connect it to the end later.
            Node* temp = head->next;
            
            // Go to child list to append it here. Do it recursively to any depth.
            head->next = flatten(head->child);
            head->next->prev = head;
            
            // After appending child list, go to end of this list.
            while (head->next) { head = head->next; }
            
            // Connect the previous next node we kept before appending children, to the end of current list and check if next node existed before appending this child list.
            head->next = temp;
            if (temp) { temp->prev = head; }
            
            // Check if this is end of List , if not Move to next node of current List to proceed further.
            if (head->next) { head = head->next; }
            
            // Set child list pointer to NULL.
            start_node->child = nullptr;
        }
        
        head->next = flatten(head->next);
        
        return start_node;
    }
};