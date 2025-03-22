#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/merge-two-binary-trees/
// Difficulty : Easy

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH : UNOPITIMIZED RAW LOGIC */
class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    
            TreeNode* left, *right;
    
            if (root1) {
                if (root2) { 
                    left = mergeTrees(root1->left,root2->left); 
                    right = mergeTrees(root1->right,root2->right);
                    return new TreeNode(root1->val + root2->val,left,right); 
                }
                else { 
                    left = mergeTrees(root1->left,nullptr); 
                    right = mergeTrees(root1->right,nullptr);
                    return new TreeNode(root1->val,left,right); 
                }
            }
            else if (root2) { 
                left = mergeTrees(nullptr,root2->left); 
                right = mergeTrees(nullptr,root2->right);
                return new TreeNode(root2->val,left,right); 
            }
    
            return nullptr;
        }
};

/* OPTIMIZED LOGIC */
class Solution {
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    
            if (!root1) { return root2; }
            if (!root2) { return root1; }
    
            TreeNode* left = mergeTrees(root1->left,root2->left);
            TreeNode* right = mergeTrees(root1->right,root2->right);
            
            return new TreeNode(root1->val+root2->val,left,right);
        }
};