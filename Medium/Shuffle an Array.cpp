#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/shuffle-an-array/
// Difficulty : Medium 

/* 
    RANDOMIZED : Each time, select a index that was not selected before, randomly using rand() for getting random index.
                 Use mode operator to ensure we don't go out-of-bounds.
                 Use a Hash Set to ensure we don't select indices that were previously selected.

*/
class Solution {
public:
    vector<int> nums;
    int n;

    Solution(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        srand(time(nullptr));
    }
    
    vector<int> reset() { return nums; }
    
    vector<int> shuffle() {
        vector<int> shuffled(n,-1);
        unordered_set<int> hs;
        for (int i=0;i<n;i++) { hs.insert(i); }
        for (int i=0;i<n;i++) {
            int idx = -1;
            while (hs.find(idx) == hs.end()) { idx = rand() % n; }
            shuffled[i] = nums[idx];
            hs.erase(idx);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */