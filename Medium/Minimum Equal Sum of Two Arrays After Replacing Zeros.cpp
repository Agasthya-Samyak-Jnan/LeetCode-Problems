#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
// Difficulty : Medium 

/* GREEDY + INTUITION */
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long zarr1 = 0, zarr2 = 0, sum1 = 0, sum2 = 0;

        for (auto num : nums1) {
            if (num == 0) { zarr1++; }
            else { sum1 += num; }
        }

        for (auto num : nums2) {
            if (num == 0) { zarr2++; }
            else { sum2 += num; }
        }

        if ((sum1+zarr1)>(sum2+zarr2) and zarr2 == 0) { return -1; }
        if ((sum1+zarr1)<(sum2+zarr2) and zarr1 == 0) { return -1; }


        return max(sum1+zarr1,sum2+zarr2);
    }
};