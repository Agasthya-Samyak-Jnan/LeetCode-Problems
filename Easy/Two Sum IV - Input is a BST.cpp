#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* HASH SET + DEPTH-FIRST SEARCH - STORE COMPLEMENT OF EACH NUMBER IN THEIR SUM TO 'K' */
class Solution {
public:
    
    unordered_set<int> mp;

    bool findTarget(TreeNode* root, int k) {
        if (!root) { return false; }
        if (mp.find(root->val) != mp.end()) { return true; }
        mp.insert(k - root->val);
        return findTarget(root->left,k) | findTarget(root->right,k);
    }
};