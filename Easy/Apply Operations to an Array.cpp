#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/apply-operations-to-an-array/
// Difficulty : Easy

/* SIMULATION FOR OPERATION AND TWO POINTERS FOR ZERO SHIFTING */
class Solution {
    public:
        vector<int> applyOperations (vector<int>& nums) {
            
            int n = nums.size();
    
            for (int i=0;i<n-1;i++) {
                if (nums[i] == nums[i+1]) { 
                    nums[i] *= 2; 
                    nums[i+1] = 0; 
                }
            }
    
            int j = 0;
            for (int i=0;i<n;i++) {
                if (nums[i] != 0) {
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
    
            return nums;
        }
};
