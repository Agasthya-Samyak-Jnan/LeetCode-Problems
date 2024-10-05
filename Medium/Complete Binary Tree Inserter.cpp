#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/complete-binary-tree-inserter/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* QUEUE + BREADTH-FIRST SEARCH (INSERT = REVERSE BFS - DIVIDED INTO SINGLE STEP) */
class CBTInserter {
public:
    
    TreeNode* root, *new_curr;
    queue<TreeNode*> q;
    
    CBTInserter(TreeNode* Root) {

        queue<TreeNode*> Q;
        root = new TreeNode(Root->val);
        
        q.push(root);
        if (Root->left) { Q.push(Root->left); }
        if (Root->right) { Q.push(Root->right); }
        
        while(!Q.empty()) {
            
            TreeNode* curr = Q.front(); Q.pop();
            
            insert(curr->val);
            
            if (curr->left) { Q.push(curr->left); }
            if (curr->right) { Q.push(curr->right); }       
        }   
    }
    
    int insert(int val) {    
        
        bool inserted = false; 
        while (!inserted) {
                
            new_curr = q.front();
            
            if (!new_curr->left) { 
                new_curr->left = new TreeNode(val); 
                q.push(new_curr->left);
                inserted = true;
            }
            else if (!new_curr->right) {
                new_curr->right = new TreeNode(val); 
                q.push(new_curr->right);
                inserted = true;
            }
            else { q.pop(); }
        }
        
        return new_curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};
