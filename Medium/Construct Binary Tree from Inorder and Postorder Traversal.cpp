#include<bits/stdc++.h>

using namespace std;

// Link to  the Problem : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DIVIDE AND CONQUER METHOD  - TC : O(n^2) , SC : O(n) */
class Solution {
public:
    vector<int> postorder;
    vector<int> inorder;
    int n;
    
    TreeNode* builder (int postend, int instart, int inend) {
        
        if (instart >= inend) { return nullptr; }
        
        int divide = instart, nodeval = postorder[postend];
        
        while (inorder[divide] != nodeval) { divide++; }
        
        int rightSize = inend - divide;
        
        TreeNode* left = builder(postend-rightSize,instart,divide);
        TreeNode* right = builder(postend-1,divide+1,inend);
        
        return new TreeNode (nodeval,left,right);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        n = inorder.size();
        this->postorder = postorder;
        this->inorder = inorder;
        
        return builder(n-1,0,n);
        
    }
};

/* DIVIDE AND CONQUER + HASH TABLE - TC : O(n) , SC : O(n) */
class Solution {
public:
    vector<int> postorder;
    vector<int> inorder;
    int n;
    unordered_map<int,int> mp;
    
    TreeNode* builder (int postend, int instart, int inend) {
        
        if (instart >= inend) { return nullptr; }
        
        int nodeval = postorder[postend], divide = mp[nodeval];
        
        int rightSize = inend - divide;
        
        TreeNode* left = builder(postend-rightSize,instart,divide);
        TreeNode* right = builder(postend-1,divide+1,inend);
        
        return new TreeNode (nodeval,left,right);
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        n = inorder.size();
        this->postorder = postorder;
        this->inorder = inorder;
        for (int i=0;i<n;i++) { mp[inorder[i]] = i; }
        
        return builder(n-1,0,n);
        
    }
};