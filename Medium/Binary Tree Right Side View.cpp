#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-right-side-view/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* MODIFIED DEPTH-FIRST SEARCH (RIGHT ALWAYS FIRST) + HASH TABLE (TO CHECK IF RIGHT MOST NODE WAS FOUND AT A LEVEL) */
class Solution {
public:
    unordered_map<int,int> mp;
    vector<int> ans;
    
    void dfs (TreeNode* root, int level) {
        if (!root) { return; }
        if (mp[level] == 0) {
            if (root->right) { ans.push_back(root->right->val); mp[level] = 1; }
            else if (root->left) { ans.push_back(root->left->val); mp[level] = 1; }
            else { return; }
        }
        dfs(root->right,level+1);
        dfs(root->left,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root) { return {}; }
        
        ans = {root->val};
        dfs(root,1);
        return ans;
    }
};

/* BREADTH-FIRST SEARCH (LEFT TO RIGHT, NORMAL) */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (root == nullptr) { return {}; }
        
        vector<int> ans;
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
           ans.push_back(level[l_size-1]);
        }
        return ans;
    }
};

/* MODIFIED BREADTH-FIRST SEARCH WITHOUT USING LEVEL ARRAY. (RIGHT TO LEFT, FIRST NODE OF EACH LEVEL IS RIGHTMOST NODE)*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (root == nullptr) { return {}; }
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
           int l_size = q.size();
           for (int i=0;i<l_size;i++) {
               root = q.front(); q.pop();
               if (i == 0) { ans.push_back(root->val); }
               if (root->right != nullptr) { q.push(root->right); }
               if (root->left != nullptr) { q.push(root->left); }
           }
        }
        
        return ans;
    }
};