#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/cousins-in-binary-tree/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* COUSINS = TWO NODES AT SAME LEVEL BUT DIFFERENT PARENT NODES */

/* BREADTH-FIRST SEARCH with LEVEL SEPERATION - STORE EACH NODE WITH ITS PARENT */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<pair<TreeNode*,TreeNode*>> q;
        int found = 0;

        q.push({root,nullptr});

        while (!q.empty()) {
            int l = q.size();
            TreeNode *x_par = nullptr, *y_par = nullptr;
            for (int i=0;i<l;i++) {
                auto [root,parent] = q.front(); q.pop();
                x_par = (root->val == x) ? parent : x_par;
                y_par = (root->val == y) ? parent : y_par;
                if (root->left) { q.push({root->left,root}); }
                if (root->right) { q.push({root->right,root}); }
            }
            if (x_par and y_par) { return (x_par != y_par); }
            if (x_par or y_par) { return false; }
        }

        return false;
    }
};

/* DEPTH-FIRST SEARCH */
class Solution {
public:

    vector<pair<TreeNode*,int>> cousins;
    int x,y;

    void dfs (TreeNode* root, TreeNode* parent, int level) {
        if (!root) { return; }
        if (root->val == x or root->val == y) { cousins.push_back({parent,level}); return; }
        dfs(root->left,root,level+1);
        dfs(root->right,root,level+1);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root,nullptr,0);
        return (cousins.size() < 2 or cousins[0].first == cousins[1].first) ? false : (cousins[0].second == cousins[1].second);
    }
};