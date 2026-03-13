#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/k-th-largest-perfect-subtree-size-in-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* RECURSIVE VERIFYING LOGICS USING DEPTH-FIRST SEARCH */
class Solution {
public:
    priority_queue<int> pq;

    int isPerfect (TreeNode* root) {
        if (!root) { return 0; } 
        auto left = isPerfect(root->left);
        auto right = isPerfect(root->right);
        if (left == right and left != -1 and right != -1) { // Nodes with depth of both subtrees same become part of a perfect subtree.
            pq.push(pow(2,1+left)-1); // A perfect tree always has (2^(depth) - 1) nodes.
            return (1+left); 
        } 
        return -1; // not perfect
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        isPerfect(root);
        while (k>1 and !pq.empty()) {
            pq.pop(); 
            k--;
        }
        return pq.empty() ? -1 : pq.top();
    }
};