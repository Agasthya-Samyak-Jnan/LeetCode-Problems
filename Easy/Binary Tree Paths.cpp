#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/binary-tree-paths/
// Difficulty : Easy

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH  + BACKTRACKING THE PATH WE GO DOWN EACH TIME */
class Solution {
public:
    vector<string> ans;
    
    void dfs (TreeNode* root,string temp) {
        if (!root->left && !root->right) { ans.push_back(temp); }
        if (root->left) { dfs(root->left,temp + "->" + to_string(root->left->val)); }
        if (root->right) { dfs(root->right,temp + "->" + to_string(root->right->val)); }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,to_string(root->val));
        return ans;
    }
};

/* PYTHON3 VERSION 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def __init__ (self) :
        self.ans = []
        
    def dfs (self, root: TreeNode, path: string) :
        
        if not root.left and not root.right :
            self.ans.append(path + str(root.val))
            return
        
        if root.left :
            self.dfs(root.left,path + str(root.val) + "->")

        if root.right :
            self.dfs(root.right,path + str(root.val) + "->")
        
        
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        
        self.dfs(root,"")
        return self.ans
        
*/



