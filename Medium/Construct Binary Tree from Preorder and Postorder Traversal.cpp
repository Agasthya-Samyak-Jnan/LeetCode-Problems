#include<bits/stdc++.h>

using namespace std;

// Link to  the Problem : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DIVIDE AND CONQUER + HASH TABLE - TC : O(n) , SC : O(n) */
class Solution {
public:
    vector<int> preorder;
    vector<int> postorder;
    int n;
    unordered_map<int,int> mp;
    
    TreeNode* builder (int prestart, int poststart, int postend) {
        
        if (poststart == postend) { return new TreeNode (postorder[poststart]); }
        if (poststart > postend) { return nullptr; }
        
        int nodeval = preorder[prestart], divide = mp[preorder[prestart+1]];
        
        int leftSize = divide - poststart + 1;
        
        TreeNode* left = builder(prestart+1,poststart,divide);
        TreeNode* right = builder(prestart+leftSize+1,divide+1,postend-1);
        
        return new TreeNode (nodeval,left,right);
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        this->postorder = postorder;
        this->preorder = preorder;
        n = preorder.size();
        for (int i=0;i<n;i++) { mp[postorder[i]] = i; }
        return builder(0,0,n-1);
        
    }
};