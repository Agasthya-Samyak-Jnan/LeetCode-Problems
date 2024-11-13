#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/delete-nodes-and-return-forest/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH BUT ITS POSTORDER TRAVERSAL - FIRST SOLUTION */
class Solution {
public:

    TreeNode* dummy;
    unordered_map<int,TreeNode*> node;
    vector<TreeNode*> ans;
    
    void del (TreeNode* root) {
        
        if (!root) { return; }
    
        del(root->left);
        del(root->right);
        
        if (node[root->val] != dummy) { 
            node[root->val] = root; 
            if (root->left) {
                if (node[root->left->val] == dummy) { root->left = nullptr; }
                else { node.erase(root->left->val); }
            }
            if (root->right) {
                if (node[root->right->val] == dummy) { root->right = nullptr; }
                else { node.erase(root->right->val); }
            }
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        dummy = new TreeNode(0);
        
        for (auto i : to_delete) { node[i] = dummy; }
        
        del(root);
        
        for (auto i : node) { if (i.second != dummy) { ans.push_back(i.second); } }
        
        return ans;
    }
};

/* DEPTH-FIRST SEARCH BUT ITS POSTORDER TRAVERSAL - BEST SOLUTION - OPTIMIZED */
class Solution {
public:
    
    TreeNode* dummy;
    unordered_map<int, TreeNode*> node;
    vector<TreeNode*> ans;
    
    TreeNode* del(TreeNode* root) {
        
        if (!root) return nullptr;
        
        // Recursively delete in left and right subtrees
        root->left = del(root->left);
        root->right = del(root->right);
        
        // Check if this node is in the map and needs to be deleted
        if (node[root->val] == dummy) {
            // If it has children, add them as new roots to the forest
            if (root->left) { ans.push_back(root->left); }
            if (root->right) { ans.push_back(root->right); }
            
            // Return nullptr to delete this node AT ITS PARENT.
            return nullptr;
        }
        
        // If node is NOT deleted.
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        // Marker to delete nodes.
        dummy = new TreeNode(0);
        
        // Mark nodes to be deleted in the map
        for (int i : to_delete) { node[i] = dummy; }
        
        // Start the deletion - if root is not deleted, add it to forest.
        if (del(root)) { ans.push_back(root); }
        
        return ans;
    }
};