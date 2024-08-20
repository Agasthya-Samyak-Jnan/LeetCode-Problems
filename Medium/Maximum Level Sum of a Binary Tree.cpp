#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* SIMPLE APPLICATION OF BREADTH-FIRST SEARCH */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int maximum = INT_MIN,l=1,maxl=1;
        
        while (!q.empty()) {
            
            int lsize = q.size();
            int sum = 0;
            
            for (int i=0;i<lsize;i++) {
                root = q.front(); q.pop();
                sum += root->val;
                if (root->left) { q.push(root->left); }
                if (root->right) { q.push(root->right); }
            }
            
            if (maximum < sum) { maximum = sum; maxl = l; }
            l++;
        }
        
        return maxl;
    }
};