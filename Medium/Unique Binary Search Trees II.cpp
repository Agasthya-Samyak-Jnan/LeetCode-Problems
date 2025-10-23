#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Difficulty: Medium

using namespace std; 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Combined Logical Concepts from these Questions : Permutations, Serialize and Deserialize Binary Tree, Insert into a Binary Search Tree */

/* BAKCTRACKING + BINARY SEARCH TREE IDEAS + SERIALIZATION OF DATA STRUCTURES + HASH TABLE */
class Solution {
public:

    /* Finding all permutations of an array using Backtracking */
    vector<vector<int>> permutations (vector<int> nums, int i) {
        if (i == nums.size()) { return {nums}; }
        vector<vector<int>> p;
        for (int j=i;j<nums.size();j++) {
            swap(nums[i],nums[j]);
            for (auto perm : permutations(nums,i+1)) { p.push_back(perm); }
            swap(nums[i],nums[j]);
        }
        return p;
    }

    /* BINARY SEARCH TREE Helper Functions */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) { return new TreeNode(val); }
        if (val >= root->val) { root->right = insertIntoBST(root->right,val); }
        else { root->left = insertIntoBST(root->left,val); }
        return root;
    }
    TreeNode* buildBST (vector<int>& nodes) {
        TreeNode* root = new TreeNode(nodes[0]);
        for (int i=1;i<nodes.size();i++) { insertIntoBST(root,nodes[i]); }
        return root;
    }   

    /* Conversion of Binary Trees into String - Serialization */
    string serialize (TreeNode* root) {
        if (!root) { return ""; }
        string subtree = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        return subtree;
    }

    vector<TreeNode*> generateTrees(int n) {

        /* BSTs contain nodes numbered from 1 to N - can be represented by an array with numbers 1 to N */
        vector<int> nodes(n);
        iota(nodes.begin(),nodes.end(),1);

        /* Get all possible arrangements of numbers in this array - can be used to build all structurally possible BSTs */
        vector<vector<int>> arrangements = permutations(nodes,0);

        /* 
            - Build a BST out of each arrangement.
            - Serialize each BST to string to use it as a key in Hash Table for duplicate tree checks.
            - If BST of this structure is not a duplicate, add it the 'trees' list.
        */
        vector<TreeNode*> trees;
        unordered_map<string,int> TreeFound;
        for (auto& arrangement : arrangements) {
            TreeNode* tree = buildBST(arrangement);
            string serialized_tree = serialize(tree);
            if (!TreeFound[serialized_tree]) { trees.push_back(tree); }
            TreeFound[serialized_tree] = 1;
        }

        return trees;
    }
};