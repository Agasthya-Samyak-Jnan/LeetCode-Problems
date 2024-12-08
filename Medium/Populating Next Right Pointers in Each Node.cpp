#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
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
                if (root->right) { 
                    q.push(root->left); 
                    q.push(root->right); 
                }
            }
        }
        
        return ROOT;
    }
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    
    void dfs (Node* root) {
        if (!root or !root->left) { return; }
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};

// Concise Edition
class Solution {
public:
    Node* connect(Node* root) {
        
        if (!root || !root->left) { return root; }
        
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : nullptr;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};