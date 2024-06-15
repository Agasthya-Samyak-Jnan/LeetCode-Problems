#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Difficulty : Easy

// Definition for "Node" of a N-Ary Tree
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/* Iterative Solution Using Stack */
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> stack; 
        vector<int> a; 
        stack.push(root);
        while(!stack.empty()) 
        {
            root=stack.top();
            stack.pop();
          if (root) {
            a.push_back(root->val);
            for(int i=root->children.size()-1;i>=0;i--) {
                stack.push(root->children[i]);
            }
          }
        }
        return a;
    }
};

/* Recursive Solution */
class Solution {
public:
    void pre (Node* root,vector<int> &a) {
         if (root == NULL) { return; }
         a.push_back(root->val);
         for (auto node: root->children) {
             pre(node,a);
         }
    }
    vector<int> preorder(Node* root) {
        vector<int> a;
        pre(root,a);
        return a;
    }
};