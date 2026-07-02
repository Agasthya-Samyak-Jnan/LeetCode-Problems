#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Difficulty : Medium

/* SLIDING WINDOW OF SIZE 'K' + HASH TABLE TO TRACK FREQUENCIES OF NUMBERS IN WINDOW (SUBARRAY) TO CHECK IF ANY NUMBER REPEATS WITHIN SUBARRAY */
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        long long sum = 0, max_sum = 0;
        int i = 0, n = nums.size();
        unordered_map<int,int> mp;

        while (i<k) { 
            sum += nums[i]; 
            mp[nums[i]]++;
            i++; 
        }

        if (mp.size() == k) { max_sum = max(max_sum,sum); }

        while (i<n) {
            sum -= nums[i-k];
            if (--mp[nums[i-k]] == 0) { mp.erase(nums[i-k]); }
            sum += nums[i]; 
            mp[nums[i]]++;
            if (mp.size() == k) { max_sum = max(max_sum,sum); }
            i++; 
        }

        
        return max_sum;
    }
};