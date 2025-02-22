#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Difficulty : Medium

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH */
class Solution {
    public:
    
        int dfs (TreeNode* root, int X) {
            if (!root) { return 0; }
            return (root->val>=X) + dfs(root->left,max(root->val,X)) + dfs(root->right,max(root->val,X));
        }
    
        int goodNodes(TreeNode* root) {
            return dfs(root,-10001);
        }
};

/* BREADTH-FIRST SEARCH */
class Solution {
    public:
    
        int bfs (TreeNode* root) {
            
            queue<pair<TreeNode*,int>> q;
            int good_nodes = 1;
            q.push({root,root->val});
    
            while (!q.empty()) {
                auto [root,X] = q.front(); q.pop();
                if (root->left) {
                    if (root->left->val >= X) { good_nodes++; }
                    q.push({root->left,max(root->left->val,X)});
                }
                if (root->right) {
                    if (root->right->val >= X) { good_nodes++; }
                    q.push({root->right,max(root->right->val,X)});
                }
            }
            
            return good_nodes;
        }
    
        int goodNodes(TreeNode* root) {
            return bfs(root);
        }
};