#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/flip-equivalent-binary-trees/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH - CHECK IF FLIPPING OR NOT FLIPPING SUBTREE FROM EACH NODE MATCHES THE GIVEN TREE'S SUBTREE AT RESPECTIVE NODE RECURSIVELY. */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if (!root1 and !root2) { return true; }
        if ((!root1 xor !root2) or root1->val != root2->val) { return false; }

        bool not_flipped = flipEquiv(root1->left,root2->left) and flipEquiv(root1->right,root2->right);
        bool flipped = not_flipped == true or (flipEquiv(root1->right,root2->left) and flipEquiv(root1->left,root2->right));

        return not_flipped or flipped;
    }
};