#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/balance-a-binary-search-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Time Complexity: O(N) = 2N , Space Complexity: O(N) = N */
class Solution {
public:
    vector<int> BST;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        BST.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* balanceorder (int i, int j) {  // Partitions Array Like Merge Sort
         if (i>j) { return nullptr; }
             int mid = (i+j)/2;
             TreeNode* root = new TreeNode(BST[mid]);
             root->left = balanceorder(i,mid-1);
             root->right = balanceorder(mid+1,j);
             return root;
    }
        
    TreeNode* balanceBST(TreeNode* root) {    
        inorder(root);
        return balanceorder(0,BST.size()-1); // Works Similar to Merge Sort            
    }
};