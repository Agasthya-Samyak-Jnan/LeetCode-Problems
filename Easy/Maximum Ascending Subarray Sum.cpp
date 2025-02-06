#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-ascending-subarray-sum/
// Difficulty : Easy

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n = nums.size(), sum = nums[0], max_sum = 0;

        for (int i=1;i<n;i++) {
            if (nums[i-1] < nums[i]) { sum += nums[i]; } 
            else {
                max_sum = max(sum,max_sum);
                sum = nums[i];
            }
        }

        return max(sum,max_sum);
    }
};

