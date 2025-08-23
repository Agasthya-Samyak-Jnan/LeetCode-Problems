#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Difficulty : Medium 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH AND LOWEST COMMON ANCESTOR FOR PATHS IN TREES BETWEEN TWO NODES */
class Solution {
public:

    TreeNode* LCA = nullptr;
    string LCA_to_src = "", LCA_to_dest = "";

    TreeNode* findNearestCommonAncestor (TreeNode* root, int src, int dest) {

        if (!root) { return nullptr; }

        TreeNode* left = findNearestCommonAncestor(root->left,src,dest);
        TreeNode* right = findNearestCommonAncestor(root->right,src,dest);

        if ((left and left->val == src) or (right and right->val == src)) { LCA_to_src += 'U'; }
        if (left and left->val == dest) { LCA_to_dest += 'L'; }
        if (right and right->val == dest) { LCA_to_dest += 'R'; }

        if (root->val == src or root->val == dest) { return root; }
        if (left and right) { return root; }

        return left ? left : right; 
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        LCA = findNearestCommonAncestor(root,startValue,destValue);
        reverse(LCA_to_dest.begin(),LCA_to_dest.end());

        if (LCA->val == startValue) { return LCA_to_dest; }
        if (LCA->val == destValue) { return LCA_to_src; }
        string path = LCA_to_src + LCA_to_dest;

        return path;
    }
};
