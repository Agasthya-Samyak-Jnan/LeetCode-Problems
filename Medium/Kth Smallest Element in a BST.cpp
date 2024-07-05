#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Inorder Traversal + Array : TC = O(K) , SC = O(K+K) (Stack+Array) */
class Solution {
public:
    int k;
    vector<int> arr;
    
    void inorder (TreeNode* root) {
        if (!root || arr.size() >= k) { return; }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        if (!root->left && !root->right) { return root->val; }
        
        this->k = k;
        inorder(root);

        return arr[k-1];
    }
};