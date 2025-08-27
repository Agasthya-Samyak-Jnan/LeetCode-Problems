#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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

    int sumEvenGrandparent(TreeNode* root) {
        
        int sum = 0;

        if (root->left) { 
            sum += sumEvenGrandparent(root->left);
            if (root->val % 2 == 0) {
                if (root->left->left) { sum += root->left->left->val; }
                if (root->left->right) { sum += root->left->right->val; }
            }
        }

        if (root->right) { 
            sum += sumEvenGrandparent(root->right);
            if (root->val % 2 == 0) {
                if (root->right->left) { sum += root->right->left->val; }
                if (root->right->right) { sum += root->right->right->val; }
            }
        }

        return sum;
    }
};

/* BREADTH-FIRST SEARCH */
class Solution {
public:

    int sumEvenGrandparent(TreeNode* root) {
        
        int sum = 0;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int l =  q.size();
            for (int i=0;i<l;i++) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left) { 
                    q.push(curr->left);
                    if (curr->val % 2 == 0) {
                        if (curr->left->left) { sum += curr->left->left->val; }
                        if (curr->left->right) { sum += curr->left->right->val; }
                    }
                }
                if (curr->right) { 
                    q.push(curr->right); 
                    if (curr->val % 2 == 0) {
                        if (curr->right->left) { sum += curr->right->left->val; }
                        if (curr->right->right) { sum += curr->right->right->val; }
                    }
                }
            }
        }

        return sum;
    }
};