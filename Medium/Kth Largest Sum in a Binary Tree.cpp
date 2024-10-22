#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
// Difficulty : Medium 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// N = Number of Nodes in Tree , L = Number of Levels in Tree

/* BREADTH-FIRST SEARCH + SORTING */
// Time Complexity : O(N + L*log(L))
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        vector<long long> sums;
        int i,n=0;
        
        q.push(root);
        
        while (!q.empty()) {
            i = q.size(); 
            long long sum = 0;
            while (i) {
                TreeNode* curr = q.front(); q.pop();
                sum += curr->val;
                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
                i--;
            }
            n++;
            sums.push_back(sum);
        }
        
        if (n<k) { return -1; }
        
        // Reverse Sorting
        sort(sums.begin(),sums.end(),greater<long long>());
        
        return sums[k-1];
    }
};

/* BREADTH-FIRST SEARCH + QUICKSELECT */
// Time Complexity : O(N + L)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        vector<long long> level_sums;
        int i,n=0;
        
        q.push(root);
        
        while (!q.empty()) {
            i = q.size(); 
            long long sum = 0;
            while (i) {
                TreeNode* curr = q.front(); q.pop();
                sum += curr->val;
                if (curr->left) { q.push(curr->left); }
                if (curr->right) { q.push(curr->right); }
                i--;
            }
            n++;
            level_sums.push_back(sum);
        }
        
        if (n<k) { return -1; }
        
        // Built in C++ Library Function - Uses "Quick Select" Technique.
        /* This function finds 'n'th element in sorted order of a vector and 
           places it in 'n'th index of vector. Vector might be jumbled in the process. */
        // We use this to find Kth Largest Sum in "Sums" vector.
        nth_element(level_sums.begin(),level_sums.begin()+n-k,level_sums.end());
        
        return level_sums[n-k];
    }
};