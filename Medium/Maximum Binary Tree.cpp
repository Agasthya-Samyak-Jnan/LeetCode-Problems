#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-binary-tree/
// Difficulty : Medium

/* 
    NOTE :
    * A Tree built this way outputs the same array under InOrder Traversal. Such a tree is called CARTESIAN Tree.
    * This problem can be solved in LINEAR time using MONOTONIC STACK.
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DIVIDE AND CONQUER METHOD */
class Solution {
public:
    
    // Function to find Maximum Value's Index in Array.
    int findMax (vector<int>& nums, int start, int end) {
        int mx_index = start;
        for (int i=start;i<=end;i++) { if (nums[mx_index] < nums[i]) { mx_index = i; } }
        return mx_index;
    }
    
    // Recursive Tree Builder.
    TreeNode* buildTree (vector<int>& nums, int start, int end) {
        if (start <= end) {
            int i = findMax(nums,start,end);
            return new TreeNode(nums[i],buildTree(nums,start,i-1),buildTree(nums,i+1,end));
        }
        return nullptr;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {        
        return buildTree(nums,0,nums.size()-1);
    }
};