#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/missing-number/
// Difficulty : Easy

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),sum=0;
        for (int i=0;i<n;i++) { sum += nums[i]; } // Sum of Array with missing numbers
        return n*(n+1)/2 - sum; // Sum should be sum of all natural numbers, but one number is missing,
                                // that number is difference in array and set of natural numbers till 'n'.
    }
};