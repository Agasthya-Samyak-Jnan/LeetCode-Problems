#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/cousins-in-binary-tree-ii/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BREADTH-FIRST SEARCH with LEVEL SEPERATION : LEVEL SUM - SIBLINGS' SUM = COUSINS' SUM */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        TreeNode* ROOT = new TreeNode(0,root,nullptr);
        queue<pair<TreeNode*,TreeNode*>> q;
        vector<pair<TreeNode*,int>> level; // {Node, Siblings' Sum}
        int level_size, level_sum;

        q.push({root,ROOT});

        while (!q.empty()) {
            level_size = q.size(), level_sum = 0; // level_sum = siblings' sum + cousins' sum
            for (int i=0;i<level_size;i++) {
                auto [root, parent] = q.front(); q.pop();
                level_sum += root->val;
                level.push_back({root, (parent->left ? parent->left->val : 0) + (parent->right ? parent->right->val : 0)});
                if (root->left) { q.push({root->left, root}); }
                if (root->right) { q.push({root->right, root}); }
            }
            for (auto node : level) {
                node.first->val = level_sum - node.second;
            }
            level.clear();
        }

        return ROOT->left;
    }
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:
    unordered_map<int,int> level_sum;
    unordered_map<TreeNode*,int> siblings_sum;
    
    void dfs1 (TreeNode* root, int depth) {
        if (!root) { return; }
        level_sum[depth] += root->val;
        if (root->left) { 
            siblings_sum[root->left] += root->left->val; 
            if (root->right) { siblings_sum[root->right] += root->left->val; }
            dfs1(root->left, depth + 1); 
        }
        if (root->right) { 
            if (root->left) { siblings_sum[root->left] += root->right->val; }
            siblings_sum[root->right] += root->right->val;
            dfs1(root->right, depth + 1);
        }
    }

    void dfs2 (TreeNode* root, int depth) {
        if (!root) { return; }
        root->val = level_sum[depth] - siblings_sum[root];
        dfs2(root->left, depth + 1);
        dfs2(root->right, depth + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        siblings_sum[root] = root->val;
        dfs1(root,0);
        dfs2(root,0);
        return root;
    }
};