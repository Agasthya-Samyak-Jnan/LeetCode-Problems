#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-bottom-left-tree-value/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Depth-First-Search Solution: Time Complexity: O(n) [ Breadth-First-Search Solution also Works! ] */
class Solution {
public:
    
    int max_depth;
    int bottom_left;
    
    Solution () {
        max_depth = 0;
        bottom_left = 0;
    }
    
    void dfs (TreeNode* root,int depth) {
        if(root == nullptr) { return; }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
        if (!root->left && !root->right) {
            if (depth > max_depth) {
                max_depth = depth;
                bottom_left = root->val;
            }
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,1);
        return bottom_left;
    }
};