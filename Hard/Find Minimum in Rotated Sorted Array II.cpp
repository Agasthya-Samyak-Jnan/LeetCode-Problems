#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Difficulty : Hard

/* BINARY SEARCH = REDUCE HALF OF THE SEARCH SPACE LOGICALLY AT EACH STEP */
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1, mid;
        
        while (low < high) {
            mid = (low+high)/2;
            if (nums[mid] > nums[high]) { low = mid + 1; }
            // Handle Duplicates
            else if (nums[mid] == nums[high]) { high--; }
            else { high = mid; }
        }
        
        return nums[low];
    }
};