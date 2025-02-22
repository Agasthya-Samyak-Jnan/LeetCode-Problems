#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Difficulty : Hard

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ITERATIVE DEPTH-FIRST SEARCH - From Intuition to Optimised Solution */

// #1
class Solution {
    public:
    
        TreeNode* recoverFromPreorder(string pre) {
    
            stack<TreeNode*> s;
            int i = 0, level = 0;
            string nodeval = "";
            TreeNode* root;
    
            while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
            root = new TreeNode(stoi(nodeval));
            s.push(root);
    
            while (pre[i] and !s.empty()) {
    
                level = 0;
                while (pre[i] == '-') { level++; i++; }
    
                if (level < s.size()) {
    
                    while (s.size() != level) { s.pop(); }
    
                    nodeval = "";
                    while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
    
                    if (s.top()->left) { 
                        s.top()->right = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->right);
                    }
                    else {
                        s.top()->left = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->left);
                    }
    
                }
                else if (level == s.size()) {
    
                    nodeval = "";
                    while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
    
                    if (s.top()->left) { 
                        s.top()->right = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->right);
                    }
                    else {
                        s.top()->left = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->left);
                    }
    
                }
                else {
    
                    nodeval = "";
                    while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
    
                    if (s.top()->left) {
                        s.top()->right = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->right);
                    }
                    else {
                        s.top()->left = new TreeNode(stoi(nodeval));
                        s.push(s.top()->left);
                    }
                }
    
            }
            
            return root;
        }
};

// #2
class Solution {
    public:
    
        TreeNode* recoverFromPreorder(string pre) {
    
            stack<TreeNode*> s;
            int i = 0, level = 0;
            string nodeval = "";
            TreeNode* root;
    
            while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
            root = new TreeNode(stoi(nodeval));
            s.push(root);
    
            while (pre[i] and !s.empty()) {
    
                level = 0;
                while (pre[i] == '-') { level++; i++; }
    
                if (level < s.size()) {
    
                    while (s.size() != level) { s.pop(); }
    
                    nodeval = "";
                    while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
    
                    if (s.top()->left) { 
                        s.top()->right = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->right);
                    }
                    else {
                        s.top()->left = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->left);
                    }
                }
                else {
    
                    nodeval = "";
                    while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
    
                    if (s.top()->left) { 
                        s.top()->right = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->right);
                    }
                    else {
                        s.top()->left = new TreeNode(stoi(nodeval)); 
                        s.push(s.top()->left);
                    }
    
                }
            }
            
            return root;
        }
};

// #3
class Solution {
    public:
    
        TreeNode* recoverFromPreorder(string pre) {
    
            stack<TreeNode*> s;
            int i = 0, level = 0;
            string nodeval = "";
            TreeNode* root;
    
            while (pre[i] and pre[i] != '-') { nodeval += pre[i]; i++; }
            root = new TreeNode(stoi(nodeval));
            s.push(root);
    
            while (pre[i] and !s.empty()) {
    
                level = 0;
                while (pre[i] == '-') { level++; i++; }
    
                if (level < s.size()) {
                    while (s.size() != level) { s.pop(); }
                }
    
                nodeval = "";
                while (pre[i] and pre[i] != '-') { 
                    nodeval += pre[i]; 
                    i++; 
                }
    
                if (s.top()->left) { 
                    s.top()->right = new TreeNode(stoi(nodeval)); 
                    s.push(s.top()->right);
                }
                else {
                    s.top()->left = new TreeNode(stoi(nodeval)); 
                    s.push(s.top()->left);
                }
            }
            
            return root;
        }
    };