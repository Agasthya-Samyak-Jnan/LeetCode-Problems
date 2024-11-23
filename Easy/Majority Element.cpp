#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/majority-element/
// Difficulty : Easy 

/* HASH TABLE SOLUTION */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for (auto& i : nums) { mp[i]++; }
        
        for (auto& i : mp) { if(i.second > n/2) { return i.first; } }
        
        return -1;
    }
};

/* SORTING SOLUTION */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size(), freq = 1;
        
        for (int i=1;i<n;i++) {
            if (nums[i-1] == nums[i]) { freq++; }
            else {
                if (freq > n/2) { return nums[i-1]; }
                freq = 1;
            }
        }
        
        return nums[n-1];
    }
};