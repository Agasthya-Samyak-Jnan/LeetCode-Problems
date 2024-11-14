#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DEPTH-FIRST SEARCH - PATH TRACING - FIND FULL PATHS TO TWO GIVEN NODE AND COMPARE THEM TILL YOU FIND THE DIFFERENCE.
class Solution {
public:
    vector<vector<TreeNode*>> paths;
    int i = 0;
    
    bool dfs (TreeNode* root, TreeNode* target) {

        if (!root) { return false; }

        paths[i].push_back(root);  // Store the current node to Path.

        if (root == target) { return true; } // If Node was found , go back no need to search further.

        if (dfs(root->left,target)  || dfs(root->right,target)) { return true; } // If Node was found , go back no need to search further.

        // If Path doesn't lead to target node.
        paths[i].pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        paths = vector<vector<TreeNode*>>(2);
        
        dfs(root,p);
        i++;
        dfs(root,q);
        
        // for (auto i : paths) {
        //     for (auto j : i) {
        //         cout<<j->val<<"->";
        //     }
        //     cout<<"\n";
        // }
        
        int p1 = paths[0].size(), p2 = paths[1].size(), i = 0, j = 0;
        
        // Compare paths till you find first different nodes in paths.
        while (i<p1 && j<p2 && paths[0][i] == paths[1][j]) { i++; j++; }
        
        return paths[0][i-1];
    }
};

/* BEST SOLUTION */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // If one of these Nodes are found , return them, Otherwise return NULL.
        if(!root || root == p || root == q) { return root; }
        
        // Check Left and Right Branches
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        // If Both Nodes were found in different branches of this node, this is a ANCESTOR of both.
        // Since this is a Depth-First Search, Deepest ANCESTOR will return itself first.
        // Since Both Nodes were found Below Deepest ANCESTOR, there is no way that both left and right branches of Higher Nodes will have the both nodes. Hence, this ANCESTOR will be propogated up through recursive calls.
        if(left && right) { return root; }
        
        // Return Node if its found.
        return left ? left : right;
    }
};