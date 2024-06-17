#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/clone-graph/
// DIfficulty : Medium

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    // The Map used to TRACK VISITED NODES + TRACK ADDRESSES OF THIER RESPECTIVE COPY NODES FOR EASY ACCESS TO IT.
    unordered_map<Node*,Node*> copy;
    
    Node* cloneGraph(Node* node) {
        
            if (node == NULL) { return NULL; } // Exception Case.
            
            // If Node is NOT found.
            if (copy.find(node) == copy.end()) { 
                
                copy[node] = new Node(node->val); // Create its Copy and Tag (Assign to) it with Respective Old Graph Node.
                
                for (auto i : node->neighbors) {  // Visit All its Neighbor Nodes
                    copy[node]->neighbors.push_back(cloneGraph(i)); // Recursion : Assign all its Neighbor nodes to it. 
                    /*  if copy exists already, simply return its address, 
                        if does NOT  exist, then create copy, visit its neighbors and then return its address after visiting. */
                }
            }

            // If Node is FOUND.         
            return copy[node];  // Return the address of created copy node.
        }
};