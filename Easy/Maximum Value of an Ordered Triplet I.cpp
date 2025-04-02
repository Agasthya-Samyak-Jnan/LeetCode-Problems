#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/
// Difficulty : Easy

/* BRUTE FORCE */
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
    
            long long max_val = INT_MIN;
            int n = nums.size();
            
            for (int i=0;i<n;i++) {
                for (int j=i+1;j<n;j++) {
                    for (int k=j+1;k<n;k++) {
                        long long curr_val = (long long)(nums[i]-nums[j])*(long long)nums[k];
                        max_val = max(max_val,curr_val);
                    }
                }
            }
    
            return (max_val < 0) ? 0 : max_val;
        }
};