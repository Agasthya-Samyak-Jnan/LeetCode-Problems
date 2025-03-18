#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/divide-array-into-equal-pairs/
// Difficulty : Easy

/* HASH SET METHOD */
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            
            unordered_set<int> mp;
    
            for (auto num : nums) {
                if (mp.find(num) == mp.end()) { mp.insert(num); }
                else { mp.erase(num); }
            }
    
            return mp.empty();
        }
};