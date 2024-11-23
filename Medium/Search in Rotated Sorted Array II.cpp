#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Difficulty : Medium

/* Application of Binary Search Idea - Find Number with respect to Sorted Part of Array - Skip the Duplicate Number by one Step. */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size(), low = 0, high = n-1, mid;
        
        while (low <= high) {
            
            mid = (low + high) / 2;
            
            if (nums[mid] == target) { return true; }
            
            // Left Half is the Sorted Half
            if (nums[mid] > nums[low]) {
                if (nums[low] < target && target < nums[mid]) { high = mid - 1; }
                else if (nums[low] == target) { return true; }
                else { low = mid + 1; }
            }
            
            // When you can't decide which half is Sorted, skip a number and move forward.
            else if (nums[mid] == nums[low]) { low++; }
            
            // Right Half is the Sorted Half
            else {
                if (nums[mid] < target && target < nums[high]) { low = mid + 1; }
                else if (nums[high] == target) { return true; }
                else { high = mid - 1; }
            }
            
        }
        
        return false;
    }
};