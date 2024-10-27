#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-subarray/
// Difficulty : Medium 

// Kadane's Algorithm.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(), max_sum = nums[0], sum = nums[0];

        for (int i=1;i<n;i++) {
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        
        return max_sum;
    }
};