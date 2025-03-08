#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/linked-list-in-binary-tree/
// Difficulty : Medium 

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* CAREFUL WHILE DOING DEPTH-FIRST SEARCH */
class Solution {
public:
    
    bool dfs (TreeNode* root, ListNode* head) {
        // Complete List Found
        if (!head) { return true; }
        // Tree Branch ended but list was not completed.
        if (!root) { return false; }
        // List Node and Tree Node match, explore branches for further matching.
        if (root->val == head->val) {
            return dfs(root->left,head->next) || dfs(root->right,head->next);
        }
        // Nodes don't Match, Stop Searching this Branch.
        return false; 
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) { return false; }
        // If and only if this Tree Node doesn't match Starting List Node itself, search its Left and Right subtrees.
        return dfs(root,head) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};


