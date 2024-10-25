#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty : Medium 

/* QUICKSELECT ALGORITHM */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin()+n-k,nums.end());
        return nums[n-k];
    }
};