#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Difficulty : Easy


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* SIMPLE DIVIDE AND CONQUER ALGORITHM */
class Solution {
public:
    vector<int> a;
    
    TreeNode* helper (int start, int end) {
        if (start > end) { return nullptr; }
        int mid = (start+end)/2;
        TreeNode* left = helper (start,mid-1);
        TreeNode* right = helper(mid+1,end);    
        return new TreeNode(a[mid],left,right);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        a = nums;
        return helper(0,nums.size()-1);
        
    }
};