#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-product-subarray/
// Difficulty : Medium 

// Kadane's Algorithm - Applied to Prefix and Suffix Products of Array
// The Product of Subarray is always Greater when including all elements from start or end, //  unless a zero comes in between. Zero partitions the array into different subarrays.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size(), prefix_prod = 1, suffix_prod = 1, ans = INT_MIN;
        
        for (int i=0;i<n;i++) {
            prefix_prod = nums[i]*prefix_prod;
            suffix_prod = nums[n-i-1]*suffix_prod;
            ans = max(ans,prefix_prod);
            ans = max(ans,suffix_prod);
            if (prefix_prod == 0) { prefix_prod = 1; }
            if (suffix_prod == 0) { suffix_prod = 1; }
        }
        
        return ans;
    }
};