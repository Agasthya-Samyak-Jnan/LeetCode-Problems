#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Difficulty : Medium 

/* BINARY SEARCH METHOD */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size(), low = 0, high = n-1, mid,prev,next;
        
        while (low <= high) {
            
            mid = (low + high)/2;
            prev = mid-1 < 0 ? 0 : mid-1;
            next = mid+1 > n-1 ? n-1 : mid+1;

            // Increasing Slope Found - then Peak might be coming next (towards Right) (then ignore Left Half). ( -----/ )
            if (nums[prev] <= nums[mid] && nums[mid] <= nums[next]) { low = mid + 1; }
            // Decreasing Slope Found - then Peak might be behind (towards Left) (then ignore Right Half). ( \----- )
            else if (nums[prev] >= nums[mid] && nums[mid] >= nums[next]) { high = mid - 1; }
            // Peak Element Found ( --/\-- )
            else if (nums[prev] <= nums[mid] && nums[mid] >= nums[next]) { return mid; }
            // A Valley (or also called 'dip' -> --\/--) was found. Choose any side, you can't decide specifically.
            else { high = mid; }
            
        }
        
        return mid;
    }
};