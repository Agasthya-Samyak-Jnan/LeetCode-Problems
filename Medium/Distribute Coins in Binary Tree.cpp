#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/distribute-coins-in-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH : POSTORDER TRAVERSAL - BECAUSE YOU WANNA ALLOW BI-DRECTIONAL MOVEMENT OF COINS/VALUES - SO YOU COMPUTE PARENT NODES ALWAYS AFTER CHILD NODES. */
class Solution {
public:

    int moves = 0;

    int postorder (TreeNode* root) {
        if (!root) { return 0; }
        int left_coins = postorder(root->left);
        int right_coins = postorder(root->right);
        int need_or_excess = root->val + left_coins + right_coins - 1; // Coins needed or excess here after distrbuting in this whole subtree.
        moves += abs(need_or_excess); // Amount of coins needed to be moved into this node (need) or out of this node (excess)
        return need_or_excess;
    }

    int distributeCoins(TreeNode* root) {
        postorder(root);
        return moves;
    }
};