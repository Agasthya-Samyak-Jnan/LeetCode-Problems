#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty : Medium 

/* BRUTE FORCE - TC : O(N^3) */
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
    
            int subarrays = 0, n = nums.size();
    
            for (int i=0;i<n;i++) {
                for (int j=i;j<n;j++) {
                    int sum = 0;
                    for (int k=i;k<=j;k++) {
                        sum += nums[k];
                    }
                    if (sum == k) { subarrays++; }
                }
            }
            
            return subarrays;
        }
};

/* USING PREFIX SUM METHOD - TC : O(N^2) */
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            
            int n = nums.size(), subarrays = 0;
            vector<int> pre(n,0);
    
            pre[0] = nums[0];
            
            for(int i=1;i<n;i++) { pre[i] = pre[i-1] + nums[i]; }
    
            for (int i=0;i<n;i++) {
                for (int j=i;j<n;j++) {
                    if (i>0) { subarrays += (pre[j] - pre[i-1] == k); } 
                    else { subarrays += (pre[j] == k); }
                }
            }
    
            return subarrays;
        }
};

/* OPTIMIZED BRUTE FORCE - TC : O(N^2) */
class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
    
            int subarrays = 0, n = nums.size();
    
            for (int i=0;i<n;i++) {
                int sum = 0;
                for (int j=i;j<n;j++) {
                    sum += nums[j];
                    if (sum == k) { subarrays++; }
                }
            }
            
            return subarrays;
        }
};