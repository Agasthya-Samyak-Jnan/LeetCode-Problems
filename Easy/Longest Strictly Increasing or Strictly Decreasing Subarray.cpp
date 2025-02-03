#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
// Difficulty : Easy

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size(), inc_len = 1, dec_len = 1, max_len = 1;

        for (int i=1;i<n;i++) {
            
            if (nums[i-1] < nums[i]) { 
                inc_len++; 
                max_len = max(max_len,inc_len);
            }
            else { inc_len = 1; }

            if (nums[i-1] > nums[i]) {
                dec_len++;
                max_len = max(max_len,dec_len);
            }
            else { dec_len = 1; }
        }

        return max_len;
    }
};