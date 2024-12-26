#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
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
    void Reverse_Level (vector<TreeNode*>& level) {
        int n = level.size();
        for (int i=0;i<n/2;i++) { swap(level[i]->val,level[n-i-1]->val); }
    }
     
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<TreeNode*> level;
        TreeNode* ROOT = root;
        int curr_level = 0;
        
        q.push(root);
        
        while (!q.empty()) {
            int l = q.size();
            for (int i=0;i<l;i++) {
                root = q.front(); q.pop();
                level.push_back(root);
                if (root->left) { q.push(root->left); }
                if (root->right) { q.push(root->right); }
            }
            if (curr_level % 2 == 1) { Reverse_Level(level); }
            level = {};
            curr_level++;
        }
        
        return ROOT;
    }
};

/*
    PYTHON3 VERSION

    
*/