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
    void Reverse_Level (queue<TreeNode*>& level) {
        int n = level.size();
        for (int i=0;i<n/2;i++) { swap(level.front()->val,level.back()->val); }
    }
     
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        TreeNode* ROOT = root;
        int curr_level = 1;
        
        q.push(root);
        
        while (!q.empty()) {
            
            int l = q.size();
            for (int i=0;i<l;i++) {
                root = q.front(); q.pop();
                if (root->left) { q.push(root->left); }
                if (root->right) { q.push(root->right); }
            }
            
            if (curr_level % 2 == 1) { Reverse_Level(q); }
            curr_level++;

        }
        
        return ROOT;
    }
};

/*
    PYTHON3 VERSION

    
*/