#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/max-consecutive-ones/
// Difficulty : Easy 

/* BASIC INTUITION */
class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            
            int max_len = 0, curr_len = 0;
    
            for (auto num : nums) {
                if (num == 1) { curr_len++; }
                else { max_len = max(max_len,curr_len); curr_len = 0; } 
            }
    
            return max(max_len,curr_len);
        }
};
