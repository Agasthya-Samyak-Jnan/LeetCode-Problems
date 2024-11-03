#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/jump-game-vi/
// Difficulty : Medium

/* RECURSIVE SOLUTION - TIME LIMIT EXCEEDED */
// TIME COMPLEXITY : O(K^N) 
class Solution {
public:
    vector<int> nums;
    int n,k;
    
    int solve (int i, int score) {
        if (i == 0) { return score; }
        int ans = 0;
        for (int j=1;j<=k;j++) {
            if (i-j >= 0) { ans = max(ans,solve(i-j,score + nums[i-j])); }
        }
        return ans;
    }
    
    int maxResult(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        this->k = k;
        return solve(n-1,nums[n-1]);
    }
};


/* RECURSION WITH MEMOISATION SOLUTION (1D MEMOISATION) - TIME LIMIT EXCEEDED */
// TIME COMPLEXITY : O(K*N) 
class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    int n,k;
    
    int solve (int i) {
        if (i == 0) { return nums[0]; }
        if (dp[i] != -1) { return dp[i]; }
        int score = INT_MIN;
        for (int j=1;j<=k;j++) {
            if (i-j >= 0) { score = max(score,nums[i]+solve(i-j)); }
        }
        
        dp[i] = score;
        return dp[i];
    }
    
    int maxResult(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        this->k = k;
        dp = vector<int>(n,-1);
        
        return solve(n-1);
    }
};

/* ITERATION WITH TABULATION SOLUTION (1D TABULATION) - TIME LIMIT EXCEEDED */
// TIME COMPLEXITY : O(K*N) 
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = vector<int>(n,INT_MIN);
        
        dp[0] = nums[0];
        
        for (int i=1;i<n;i++) {
            for (int j=1;j<=k;j++) {
                if (i-j >= 0) { dp[i] = max(dp[i],dp[i-j]+nums[i]); }
            }
        }
        
        return dp[n-1];
    }
};

/* ITERATION WITH TABULATION + SORTED CONTAINER (MULTISET + TABULATION) */
// TIME COMPLEXITY : O(N*log(K)) 
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = vector<int>(n,INT_MIN);
        multiset<int> s;
        
        dp[0] = nums[0];
        s.insert(dp[0]);
        
        for (int i=1;i<n;i++) {
            if (i > k) { s.erase(s.find(dp[i-k-1])); }
            dp[i] = *rbegin(s) + nums[i];
            s.insert(dp[i]);
        }
        
        return dp[n-1];
    }
};

/* ITERATION WITH TAABULATION + DEQUE (DEQUE + TABULATION) */
// TIME COMPLEXITY : O(N) 
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = vector<int>(n,INT_MIN);
        deque<int> dq;
        
        dp[0] = nums[0];
        dq.push_back(0);
        
        for (int i=1;i<n;i++) {
            if (dq.front() < i-k) { dq.pop_front(); }
            dp[i] = dp[dq.front()] + nums[i];
            while (!dq.empty() && dp[dq.back()] <= dp[i]) { dq.pop_back(); }
            dq.push_back(i);
        }
        
        return dp[n-1];
    }
};