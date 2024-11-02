#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/add-one-row-to-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH WITH SEPERATION OF EACH LEVEL -> ALSO CALLED AS LEVEL-ORDER TRAVERSAL */
/* Get all Nodes where you need to add new nodes to insert a row HORIZONTALLY. */

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1) { return new TreeNode(val,root,nullptr); }
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr;
        
        while (!q.empty()) {
            
            if (depth <= 2) { break; }
            
            int l = q.size();
            while (l) {
                curr = q.front(); q.pop();
                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
                l--;
            }
            
            depth--;
        }
        
        while (!q.empty()) {
            curr = q.front(); q.pop();
            curr->left = new TreeNode(val,curr->left,nullptr);
            curr->right = new TreeNode(val,nullptr,curr->right);
        }
        
        return root;
    }
};