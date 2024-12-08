#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Difficulty : Medium 

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root) { return nullptr; } 
        
        Node* ROOT = root;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int l = q.size();
            
            for (int i=0;i<l;i++) {
                root = q.front(); q.pop();
                root->next = (i == l-1) ? nullptr : q.front();
                if (root->left) { q.push(root->left); }
                if (root->right) { q.push(root->right); }
            }
        }
        
        return ROOT;
    }
};