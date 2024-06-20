#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/random-pick-index/
// Difficulty : Medium

/* Reservoir Sampling Problem */
class Solution {
public:
    vector<int> nums;
    int size;
    
    Solution(vector<int>& nums) {
        size = nums.size();
        this->nums = nums;
    }
    
    int pick(int target) {
        int index = rand()%size;
        while (nums[index] != target) { index = rand()%size; } // While Index pointing value is not 'target', keep randomising index.
        return index;                                          // Faster than searching all indices of 'target' and then picking one among them.
     }
};