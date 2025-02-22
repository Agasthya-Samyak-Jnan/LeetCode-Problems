#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/product-of-array-except-self/
// Difficulty : Medium

/* PREFIX PRODUCT AND SUFFIX PRODUCTS IN AN ARRAY - THIS SOLUTION DOESN'T USE DIVISION OPERATOR */
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            
            int n = nums.size();
            vector<int> prefix(n), suffix(n), ans(n);
            prefix[0] = nums[0];
            suffix[n-1] = nums[n-1];
    
            for (int i=1;i<n;i++) {
                prefix[i] = prefix[i-1]*nums[i];
                suffix[n-1-i] = nums[n-1-i]*suffix[n-1-(i-1)];
            }
    
            ans[0] = suffix[1];
            ans[n-1] = prefix[n-2];
            for (int i=1;i<n-1;i++) {
                ans[i] = prefix[i-1]*suffix[i+1];
            }
    
            return ans;
        }
};