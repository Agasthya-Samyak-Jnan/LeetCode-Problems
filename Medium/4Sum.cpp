#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/4sum/
// Difficulty : Medium 

/* SORTING + TWO POINTERS */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for (int i=0;i<n-3;i++) {
            if (i>0 && nums[i-1] == nums[i]) { continue; }
            for (int j=i+1;j<n-2;j++) {
                if (j>i+1 && nums[j-1] == nums[j]) { continue; }
                int left = j+1, right = n-1;
                while (left < right) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if (sum == target) { 
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++; right--;
                        while (left < right && nums[left] == nums[left-1]) { left++; }
                        while (left < right && nums[right] == nums[right+1]) { right--; }
                    }
                    else if (sum > target) { right--; }
                    else { left++; }
                }
            }
        }

        return ans;
    }
};