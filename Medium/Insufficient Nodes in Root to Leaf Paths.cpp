#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH - POSTORDER TRAVERSAL */
class Solution {
public:

    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {

        if (!root) { return nullptr; }

        /* If Node is Leaf Node and Total sum of path leading to this Leaf Node is less than limit, remove it. */
        if (!root->left and !root->right) { return ((sum+root->val)<limit) ? nullptr : root; }

        /* Check if there are any paths to Leaf whose sum more than or equal to limit */
        root->left = sufficientSubset(root->left,limit,sum+root->val);
        root->right = sufficientSubset(root->right,limit,sum+root->val);
    
        /* 
           - If both Left and Right Paths from this Node had been cut down because 
             sum of both paths were less than limit, then this node has no more paths having
             sum more than limit, and hence this node is insufficient and should be removed.
           - This Node is sufficient if it has at least 1 sufficient path whose sum is more than or equal to limit.
        */
        return (!root->left and !root->right) ? nullptr : root; 
    }
};