#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH WITHOUT REQUIRING SEPERATION OF LEVELS (SIMPLE BFS) */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool null_found = false;
        
        while (!q.empty()) {
            
            root = q.front(); q.pop();
            
            if (!root) { null_found = true; continue; }
            else if (null_found) { return false; }
            
            q.push(root->left);
            q.push(root->right);
        }
        
        return true;
    }
};