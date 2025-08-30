#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* UNDERSTANDING HOW TO DESIGN FUNCTIONS FOR PROPOGATION OF MULTIPLE VALUES ACCROSS RECURSIVE FUNCTION CALLS IN DEPTH-FIRST SEARCH */
/* YOU NEED TWO THINGS TO CALCULATE AVERAGE OF A COLLECTION OF NUMBERS : SUM OF ALL NUMBERS and TOTAL NUMBER OF NUMBERS IN COLLECTION. */
class Solution {
public:

    vector<int> dfs (TreeNode* root) {
        if (!root) { return {0,0,0}; }
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> ans = {left[0]+right[0]+root->val,left[1]+right[1]+1,left[2]+right[2]};
        if (ans[0]/ans[1] == root->val) { ans[2]++; }
        return ans; 
        // Return Value Format : {sum of subtree, no.of.numbers/nodes in subtree, no.of.nodes with average of its subtree as value in this subtree}
    }

    int averageOfSubtree(TreeNode* root) {
        return dfs(root)[2];
    }
};