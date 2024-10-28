#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/copy-list-with-random-pointer/
// Difficulty : Medium

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/* TRAVERSE THE LIST WITH DEPTH-FIRST SEARCH AND MEMORISE NEWLY CREATED NODES IN HASH TABLE TO AVOID REPEATED NODE CREATIONS. */
class Solution {
public:
    // Store New List Nodes mapped to respective old List Nodes accordingly.
    // NOTE: Mapping is "NODE TO NODE" and NOT  "VALUE TO NODE" because according to question there can be nodes with same values.
    unordered_map<Node*,Node*> copy;
    
    Node* copyRandomList(Node* head) {
        
        // If it points to nothing , return nothing.
        if (head == nullptr) { return nullptr; }
        
        // If this Node was not created in New List,
        if (copy[head] == nullptr) {
            // Create New Node and Map it to old Node.
            copy[head] = new Node(head->val);
            // Find its Next and Random neighbours by recursively checking if they exist.
            copy[head]->next = copyRandomList(head->next);
            copy[head]->random = copyRandomList(head->random);
        }
        
        // Return after new node for this old node was created.
        return copy[head];
    }
};