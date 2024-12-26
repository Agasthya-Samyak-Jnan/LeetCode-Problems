#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/even-odd-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    
    bool isEvenOddTree(TreeNode* root) {
        
       int l = 0, prev;
       queue<TreeNode*> q; 
       q.push(root);
        
       while (!q.empty()) {
           
           int l_size = q.size();
           prev = l%2 == 0 ? INT_MIN : INT_MAX;
           
           for (int i=0;i<l_size;i++) {
               root = q.front(); q.pop();
               
               if (root->val%2 == l%2) { return false; }
               if ((l%2==0 && prev>=root->val)||(l%2==1 && prev<=root->val)) { return false; }
               
               if (root->left) { q.push(root->left); }
               if (root->right) { q.push(root->right); }
               
               prev = root->val;
           }
           
           l++;
       }
        
       return true;
    }
};
