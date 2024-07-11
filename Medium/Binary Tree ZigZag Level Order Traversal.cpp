#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
       if (root == nullptr) { return {}; }
    
       vector<vector<int>> ans;
       queue<TreeNode*> q;
       q.push(root);
       int n = 0;
        
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
           n++;
       }
    
       for (int i=0;i<n;i++) { if (i%2 != 0) { reverse(ans[i].begin(),ans[i].end()); } }
          
       return ans;       
    }
};