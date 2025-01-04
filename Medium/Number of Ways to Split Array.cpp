#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-ways-to-split-array/
// Difficulty : Medium 

/* PREFIX SUM SOLUTION */
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size(), ways = 0;
        vector<long> psum(n,0);

        psum[0] = nums[0];
        for (int i=1;i<n;i++) { psum[i] = psum[i-1] + nums[i]; }
        for (int i=0;i<n-1;i++) { ways += (psum[i] >= (psum[n-1] - psum[i])); }
        return ways;

    }
};