#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Difficulty : Easy 

/* BRUTE FORCE : O(N^2) */
class Solution {
    public:
        int maxProductDifference(vector<int>& nums) {
            
            int n = nums.size(), maxProduct = INT_MIN, minProduct = INT_MAX;
    
            for (int i=0;i<n-1;i++) {
                for (int j=i+1;j<n;j++) {
                    maxProduct = max(maxProduct,nums[i]*nums[j]);
                    minProduct = min(minProduct,nums[i]*nums[j]);
                }
            }
    
            return maxProduct - minProduct;
        }
};

/* SORTING : O(NLogN) */
class Solution {
    public:
        int maxProductDifference(vector<int>& nums) {
            
            int n = nums.size();
            sort(nums.begin(),nums.end());
    
            return (nums[n-1]*nums[n-2]) - (nums[1]*nums[0]);
        }
};

/* HASH TABLE - FIND HIGHEST, SECOND HIGHEST, LOWEST, SECOND LOWEST NUMBERS : O(N) */
class Solution {
    public:
        int maxProductDifference(vector<int>& nums) {
            
            int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
    
            for (auto num : nums) {
                if (num > mx1) { mx2 = mx1; mx1 = num; } // If greater than highest, highest becomes second highest, new number becomes highest.
                else if (num > mx2) { mx2 = num; } // If lesser than highest but greater than second highest, new number should be second highest.
                if (num < mn1) { mn2 = mn1; mn1 = num; }
                else if (num < mn2) { mn2 = num; }
            }
    
            return (mx1*mx2) - (mn1*mn2);
        }
};