#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-duplicate-subtrees/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* HASH TABLE + DEPTH-FIRST SEARCH + SERIALIZATION OF TREE */
class Solution {
public:
    unordered_map<string,int> treecount;
    vector<TreeNode*> subtrees;
    
    // SERIALIZE THE TREE to easily remember in Hash Table.
    string dfs (TreeNode* root) { 
        if (!root) { return "#"; }
        string subtree = to_string(root->val) + "," + dfs(root->left) + dfs(root->right);
        // If this subtree was found previously,
        if (treecount[subtree] == 1) { subtrees.push_back(root); }
        
        treecount[subtree]++;
        return subtree;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return subtrees;
    }
};