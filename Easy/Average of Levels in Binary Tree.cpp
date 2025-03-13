#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
        vector<double> averageOfLevels(TreeNode* root) {
            
            queue<TreeNode*> q;
            q.push(root);
            vector<double> avg;
    
            while (!q.empty()) {
                int l = q.size();
                double sum = 0;
                for (int k=0;k<l;k++) {
                    root = q.front(); q.pop();
                    sum += root->val;
                    if (root->left) { q.push(root->left); }
                    if (root->right) { q.push(root->right); }
                }
                avg.push_back(sum/l);
            }
    
            return avg;
        }
    };