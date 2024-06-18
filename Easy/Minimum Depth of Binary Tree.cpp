#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/* DFS Based Solution */
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if (!root) { return 0; }
        int left = minDepth(root->left); 
        int right = minDepth(root->right);
        if (!right || !left) { return max(left,right)+1; }
        return min(left,right)+1;        
    }
};