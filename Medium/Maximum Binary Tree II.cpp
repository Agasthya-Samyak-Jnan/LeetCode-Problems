#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-binary-tree-ii/
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
    GIVEN THE QUESTION CONDITIONS AND DEFINITIONS - FOLLOWING ARE THE OBSERVATIONS : 
    - New value 'val' is "appended" to original list that was used to construct the provided tree by their custom method.
      Hence, new 'val' is the RIGHTMOST value in the list. ( That's what "append" means! )
    - Whenever you partition the tree during construction, new 'val' because of above reasons, always occurs on right branch of tree. (Because of construction Rule).
    - Since, new 'val' is LAST - RIGHTMOST value, THERE ARE NO VALUES TO ITS RIGHT, Hence, right part of new 'val' node is NULL,
      AND previously present subtree i.e which are values to left of 'val' should new node 'val's  left subtree.
*/

/* STRUCTURE OF BINARY TREES */
class Solution {
    public:
        TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
            
            if (root->val < val) { return new TreeNode(val,root,nullptr); }
    
            TreeNode* temp = root;
            while (temp and temp->right and temp->right->val > val) { temp = temp->right; }
    
            temp->right = new TreeNode(val,temp->right,nullptr);
            
            return root;
        }
};