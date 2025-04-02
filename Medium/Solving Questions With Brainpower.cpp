#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/solving-questions-with-brainpower/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSION ONLY */
class Solution {
    public:
        vector<vector<int>> q;
        int n;
    
        long long solve (int i) {
            if (i>=n) { return 0; }
            return max(q[i][0]+solve(i+q[i][1]+1),solve(i+1));
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            q = questions;
            n = questions.size();
            return solve(0);
        }
};

/* RECURSION + 1D MEMOISATION */
class Solution {
    public:
        vector<vector<int>> q;
        vector<long long > dp;
        int n;
    
        long long solve (int i) {
            if (i>=n) { return 0; }
            if (dp[i] != -1) { return dp[i]; }
            return dp[i] = max(q[i][0]+solve(i+q[i][1]+1),solve(i+1));
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            q = questions;
            n = questions.size();
            dp = vector<long long>(n,-1);
            return solve(0);
        }
};

/* CONCISE SHIT */
class Solution {
    public:
        unordered_map<int,long long> dp;
        
        long long mostPoints(vector<vector<int>>& q, int i = 0) {
            if (i>=q.size()) { return 0; }
            if (dp.find(i) != dp.end()) { return dp[i]; }
            return dp[i] = max(q[i][0]+mostPoints(q,i+q[i][1]+1),mostPoints(q,i+1));
        }
};