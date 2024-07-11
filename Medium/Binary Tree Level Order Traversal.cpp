#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH but you have to seperate each levels as "arrays". */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
       if (root == nullptr) { return {}; }
    
       vector<vector<int>> ans;
       queue<TreeNode*> q;
       q.push(root);
        
       while (!q.empty()) {
           int l_size = q.size();
           vector<int> level;
           for (int i=0;i<l_size;i++) {
               root = q.front(); q.pop();
               level.push_back(root->val);
               if (root->left != nullptr) { q.push(root->left); }
               if (root->right != nullptr) { q.push(root->right); }
           }
           ans.push_back(level);
       }
       return ans;
    }
};