#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
// Difficulty : Easy

/* HASH TABLE METHOD */
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            
            unordered_map<int,int> mp;
            int n = nums.size(), i;
    
            for (i=n-1;i>=0;i--) {
                if (mp[nums[i]]) { break; }
                mp[nums[i]] = 1;
            }
    
            return ((i+1)/3) + ((i+1)%3 > 0);
        }
};