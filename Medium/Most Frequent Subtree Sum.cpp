#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/most-frequent-subtree-sum/
// Difficulty : Medium

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DEPTH-FIRST SEARCH + HASH TABLE */

class Solution {
public:
    unordered_map<int,int> mp;
    int max_freq = 0;
    
    int dfs (TreeNode* root) {
        if (!root) { return 0; }
        int sum = root->val;
        sum += dfs(root->left);
        sum += dfs(root->right);
        mp[sum]++;
        max_freq = max(max_freq,mp[sum]);
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        vector<int> ans;
        dfs(root);
        for (auto i : mp) { if (max_freq == i.second) { ans.push_back(i.first); } }
        return ans;
    }
};