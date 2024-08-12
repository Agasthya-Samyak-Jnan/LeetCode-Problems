#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* SIMPLE BREADTH-FIRST SEARCH APPLICATION */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
       if (root == nullptr) { return {}; }
    
       vector<int> ans;
       queue<TreeNode*> q;
       q.push(root);
        
       while (!q.empty()) {
           int l_size = q.size(), maximum = INT_MIN;
           for (int i=0;i<l_size;i++) {
               root = q.front(); q.pop();
               maximum = max(maximum,root->val);
               if (root->left != nullptr) { q.push(root->left); }
               if (root->right != nullptr) { q.push(root->right); }
           }
           ans.push_back(maximum);
       }
       return ans;        
    }
};