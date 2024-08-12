#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* BASIC IDEA OF THE SOLUTION . THERE IS A OPTIMISED APPROACH THAT USES LESS TIME AND SPACE THAN THIS BELOW .*/
class BSTIterator {
public:
    vector<int> a;
    int i;
    int n;
    
    void inorder (TreeNode* root) {
        if (!root) { return; }
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        i = -1;
        n = a.size();
    }
    
    int next() {
        return a[++i];
    }
    
    bool hasNext() {
        return i >= n-1 ? 0 : 1;
    }
};

/* DECREASED INITIALISATION TIME AND SPACE */
class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
       while (root) {
           s.push(root);
           root = root->left;
       }
    }
    
    int next() {
        
        TreeNode* root = s.top(); s.pop();
        int curr = root->val;
        root = root->right;
        
        while (root) {
            s.push(root);
            root = root->left;
        }
        
        return curr;
    }
    
    bool hasNext() {
         return !s.empty();
    }
};