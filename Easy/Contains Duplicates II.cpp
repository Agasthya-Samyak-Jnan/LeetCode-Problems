#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/contains-duplicate-ii/
// Difficulty : Easy 

/* RUNNING HASH TABLE = HASH TABLE + SLIDING WINDOW - UPDATE HASH TABLE DYNAMICALLY USING SLIDING WINDOW */
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            
            unordered_map<int,int> mp;
            int n = nums.size();
    
            for (int i=0;i<n and i<=k;i++) { 
                mp[nums[i]]++; 
                if (mp[nums[i]] > 1) { return true; }
            }
    
            for (int i=1;i<n and i+k<n;i++) {
                mp[nums[i-1]]--;
                mp[nums[i+k]]++;
                if (mp[nums[i+k]] > 1) { return true; }
            }
    
            return false;
        }
};