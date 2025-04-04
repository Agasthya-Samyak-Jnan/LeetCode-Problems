#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 
    BIDIRECTIONAL BREADTH-FIRST SEARCH + HASH TABLE FOR MEMORIZING REVERSE PARENT LINKS
    DIVERGING - Go DOWNWARDS, till the Deepest Level and get list of all deepest leaves, and memorize all upward parent links for each node during this traversal.
    CONVERGING - Go UPWARDS, starting from Deepest Leaves, by going to thier parent nodes. Since, each parent has maximum of 2 Children, you eventually have Lowest Common Parent Node Left in queue.
*/

class Solution {
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    
            unordered_map<TreeNode*,TreeNode*> parent;  // Logical Representation of Reverse Links for Tree.
            unordered_map<TreeNode*,int> visited;
            queue<TreeNode*> q;
            vector<TreeNode*> level;
            TreeNode* curr;
    
            q.push(root);
    
            while (!q.empty()) {
    
                int l = q.size();
                level.clear();
    
                for (int i=0;i<l;i++) {
                    curr = q.front(); q.pop();
                    level.push_back(curr);
                    if (curr->left) { q.push(curr->left); parent[curr->left] = curr; }
                    if (curr->right) { q.push(curr->right); parent[curr->right] = curr; }
                }
    
            }   
    
            for (auto& leaf : level) { q.push(leaf); }
    
            while (q.size() > 1) {
                curr = q.front(); q.pop();
                if (!visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = 1;
                }
            }
            
            return q.front();
        }
};