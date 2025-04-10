#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION */

/* RECURSION ONLY (KINDA BACKTRACKING) - WITHOUT BITMASK - USING VECTOR - TIME LIMIT EXCEEDED */
class Solution {
    public:
        vector<int> a, used;
        int n, total_sum, k;
        
        bool solve (int i, int sum, int K, vector<int>& used) {
    
            if (sum > total_sum/k) { return false; }
            if (K == 0) { return true; }
    
            if (sum == total_sum/k) { return solve(0,0,K-1,used); }
    
            if (i >= n) { return false; }
    
            if (!used[i]) {
                used[i] = 1;
                if (solve(i+1,sum+a[i],K,used)) { return true; }
                used[i] = 0;
            }
    
            if (solve(i+1,sum,K,used)) { return true; }
    
            return false;
        }
    
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            
            a = nums;
            n = nums.size();
            used = vector<int>(n,0);
            this->k = k;
            total_sum = 0;
                
            for (auto num : nums) { total_sum += num; }
        
            if (total_sum % k != 0) { return false; }
        
            return solve(0,0,k,used);
        }
};

/* RECURSION ONLY (KINDA BACKTRACKING) - USING BITMASK - REDUCES RUNTIME AND STORAGE NEEDED TO KNOW IF A NUMBER IS USED OR NOT */
class Solution {
    public:
        
        vector<int> a;
        int n, total_sum, k, used;
        
        bool solve (int i, int sum, int K, int used) {
    
            if (sum > total_sum/k) { return false; }
            if (K == 0) { return true; }
    
            if (sum == total_sum/k) { return solve(0,0,K-1,used); }
    
            if (i >= n) { return false; }
            
            // Bitmasking Used Here
            if (((used>>i)&1) == 0) {
                used |= (1<<i);
                if (solve(i+1,sum+a[i],K,used)) { return true; }
                used &= (~(1<<i));
            }
    
            if (solve(i+1,sum,K,used)) { return true; }
    
            return false;
        }
    
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            
            a = nums;
            n = nums.size();
            used = 0;
            this->k = k;
            total_sum = 0;
                
            for (auto num : nums) { total_sum += num; }
        
            if (total_sum % k != 0) { return false; }
        
            return solve(0,0,k,used);
        }
};

/* RECURSION + 3D-MEMOISATION - USING BITMASK */
class Solution {
    public:
        unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
        vector<int> a;
        int n, total_sum, k, used;
        
        bool solve (int i, int sum, int K, int used) {
    
            if (sum > total_sum/k) { return false; }
            if (K == 0) { return true; }
    
            if (sum == total_sum/k) { return dp[sum][K][used] = solve(0,0,K-1,used); }
    
            if (dp.find(sum) != dp.end() and dp[sum].find(K) != dp[sum].end() and dp[sum][K].find(used) != dp[sum][K].end()) { 
                return dp[sum][K][used]; 
            }
    
            if (i >= n) { return false; }
    
            if (((used>>i)&1) == 0) {
                used |= (1<<i);
                if (solve(i+1,sum+a[i],K,used)) { return dp[sum][K][used] = true; }
                used &= (~(1<<i));
            }
    
            if (solve(i+1,sum,K,used)) { return dp[sum][K][used] = true; }
    
            return dp[sum][K][used] = false;
        }
    
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            
            a = nums;
            n = nums.size();
            used = 0;
            this->k = k;
            total_sum = 0;
                
            for (auto num : nums) { total_sum += num; }
        
            if (total_sum % k != 0) { return false; }
    
            return solve(0,0,k,used);
        }
};