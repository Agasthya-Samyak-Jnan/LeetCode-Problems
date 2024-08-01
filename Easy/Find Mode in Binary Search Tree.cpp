#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Diffculty : Easy


/* BST Property - Inorder Traversal of a Binary Search Tree (BST) gives Sorted Order of Nodes. */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/* WithOUT Extra Space , O(n) Time */ 
class Solution {
public:
    vector<int> modes;
    int max_freq;
    int freq;
    int prev;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        if (root->val == prev) { freq++; }
        else { freq = 1; prev = root->val; }
        if (freq > max_freq) { modes = {root->val}; max_freq = freq; }
        if (freq == max_freq) { modes.push_back(root->val); }
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        max_freq = 0, freq = 0, prev = INT_MIN;
        inorder(root);
        modes.erase(modes.begin());
        return modes;
    }
};

/* With Extra Space , O(n) Time  */
class Solution {
public:
    unordered_map<int,int> mp;
    int max_freq;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        mp[root->val]++;
        max_freq = max(max_freq,mp[root->val]);
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        inorder(root);
        for (auto i : mp) {
            if (i.second == max_freq) { modes.push_back(i.first); }
        }
        return modes;
    }
};