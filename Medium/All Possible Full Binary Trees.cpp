#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/all-possible-full-binary-trees/
// Difficulty : Medium


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* DYNAMIC PROGRAMMING SOLUTION */

/* PURE RECURSION */
class Solution {
public:
    vector<TreeNode*> solve (int n) {
        
        if (n == 1) { return {new TreeNode(0)}; }
        
        vector<vector<TreeNode*>> left, right;
        vector<TreeNode*> ans;
        
        for (int i=1;i<n;i+=2) {
            left.push_back(solve(i));
            right.push_back(solve(n-1-i));
        }
        
        for (int i=0;i<n/2;i++) {
            for (auto Ltree : left[i]) {
                for (auto Rtree : right[i]) {
                    ans.push_back(new TreeNode(0,Ltree,Rtree));
                }
            }
        }
        
        return ans;
    }
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (n%2 == 0) { return {}; }
        
        return solve(n);
    }
};

/* RECURSION with MEMOIZATION (Top-Down) - CACHING(Storing) ALL POSSIBLE FBTs that can be built with 'n' nodes in a Table. */
class Solution {
public:
    unordered_map<int,vector<TreeNode*>> dp;
    
    vector<TreeNode*> solve (int n) {
        
        if (!dp[n].empty()) { return dp[n]; }
        
        vector<vector<TreeNode*>> left, right;
        vector<TreeNode*> ans;
        
        for (int i=1;i<n;i+=2) {
            left.push_back(solve(i));
            right.push_back(solve(n-1-i));
        }
        
        for (int i=0;i<n/2;i++) {
            for (auto Ltree : left[i]) {
                for (auto Rtree : right[i]) {
                    ans.push_back(new TreeNode(0,Ltree,Rtree));
                }
            }
        }
        
        return dp[n] = ans;
    }
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (n%2 == 0) { return {}; }
        dp[1] = { new TreeNode(0) };
        
        return solve(n);
    }
};

/* ITERATION with TABULATION (Bottom-Up) - CACHING(Storing) ALL POSSIBLE FBTs that can be built with 'n' nodes in a Table. */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if (n%2 == 0) { return {}; }
        
        unordered_map<int,vector<TreeNode*>> dp;
        dp[1] = { new TreeNode(0) };
        
        for (int i=3;i<=n;i+=2) {
            for (int j=1;j<i;j+=2) {
                for (auto Ltree : dp[j]) {
                    for (auto Rtree : dp[i-1-j]) {
                        dp[i].push_back(new TreeNode(0,Ltree,Rtree));
                    }
                }
            }
        }
        
        return dp[n];
    }
};

 