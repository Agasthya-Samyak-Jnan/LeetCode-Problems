#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/monotonic-array/
// Difficulty : Easy

class Solution {
public:
    bool inline isMonotonic(vector<int>& nums) {
        
         bool increasing = false, decreasing = false;
         int n = nums.size();

         for (int i=0;i<n-1 && !(decreasing && increasing);i++) {
             if (nums[i] < nums[i+1]) { increasing = true; }
             else if (nums[i] > nums[i+1]) { decreasing = true; }
         }      
         return !(decreasing && increasing);
    }
};