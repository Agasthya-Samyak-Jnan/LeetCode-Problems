#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    int sumNumbers(TreeNode* root, int num = 0) {
        if (!root) { return 0; }
        num = num*10 + root->val;
        if (!root->left && !root->right) { return num; }
        return sumNumbers(root->left,num) + sumNumbers(root->right,num);
    }
};