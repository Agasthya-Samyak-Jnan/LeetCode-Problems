#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* SINCE ALL TREE NODES HAVE UNIQUE VALUES, FIND BY VALUE OF TARGET NODE */

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        if (!cloned or cloned->val == target->val) { return cloned; }

        TreeNode* left = getTargetCopy(original,cloned->left,target);

        return left ? left : getTargetCopy(original,cloned->right,target);
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        
        queue<TreeNode*> q;

        q.push(cloned);

        while (!q.empty()) {
            cloned = q.front(); q.pop();
            if (cloned->val == target->val) { return cloned; }
            if (cloned->left) { q.push(cloned->left); }
            if (cloned->right) { q.push(cloned->right); }
        }

        return nullptr;
    }
};