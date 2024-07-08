#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/recover-binary-search-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Time Complexity : O(N) , Space Complexity : O(N) = N + N + 2 (Array + Stack + Positions to be Swapped) */
class Solution {
public:
    vector<TreeNode*> arr;
    vector<TreeNode*> s;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        arr.push_back(root);
        if (!s[1] && arr.size() > 1 && arr[arr.size()-2]->val > root->val) { 
            s[0] = arr[arr.size()-2];
            s[1] = root;
        }
        if (s[1] && s[1]->val > root->val) { s[1] = root; } 
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
         s = {0,0};
         inorder(root);
         swap(s[0]->val,s[1]->val);
    }
};