#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Diffculty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DIVIDE AND CONQUER METHOD - TC : O(n^2), SC : O(n) */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if (preorder.size() < 1) { return nullptr; }
        
        int divide = 0;
        
        vector<int> pre,in;
        
        while (inorder[divide] != preorder[0]) { 
            in.push_back(inorder[divide]); 
            pre.push_back(preorder[divide+1]); 
            divide++; 
        }
        
        TreeNode* left = buildTree(pre,in);
        
        in.clear();
        pre.clear();
        divide++;
        while (divide < preorder.size()) {
            in.push_back(inorder[divide]);
            pre.push_back(preorder[divide]);
            divide++;
        }
         
        TreeNode* right = buildTree(pre,in);
        
        return new TreeNode(preorder[0],left,right);
    }
};

/* OPTIMIZED SPACE USAGE */
class Solution {
public:
    vector<int> preorder;
    vector<int> inorder;
    
    TreeNode* builder (int prestart, int instart, int inend) {
        
        if (instart >= inend) { return nullptr; }
        
        int nodeval = preorder[prestart];
        
        int divide = instart;
        while (inorder[divide] != nodeval) { divide++; }
        
        int leftsize = divide-instart;
        
        TreeNode* left = builder(prestart+1,instart,divide);
        TreeNode* right = builder(prestart+1+leftsize,divide+1,inend);
        
        return new TreeNode(nodeval,left,right);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return builder(0,0,inorder.size());
    }
};

/* DIVIDE AND CONQUER + HASH TABLE - TC : O(n), SC : O(n) */
class Solution {
public:
    vector<int> preorder;
    vector<int> inorder;
    int n;
    unordered_map<int,int> mp;
    
    TreeNode* builder (int prestart, int instart, int inend) {
        
        if (instart >= inend) { return nullptr; }
        
        int nodeval = preorder[prestart], divide = mp[nodeval];
        
        int leftsize = divide-instart;
        
        TreeNode* left = builder(prestart+1,instart,divide);
        TreeNode* right = builder(prestart+1+leftsize,divide+1,inend);
        
        return new TreeNode(nodeval,left,right);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        n = inorder.size();
        for (int i=0;i<n;i++) { mp[inorder[i]] = i; }
        return builder(0,0,inorder.size());
    }
};