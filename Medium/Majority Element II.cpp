#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/majority-element-ii
// Difficulty : Medium

/* HASH TABLE METHOD */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        
        for (auto& i : nums) { mp[i]++; }
        for (auto& p : mp) {
            if (p.second > n/3) { ans.push_back(p.first); }
        }
        
        return ans;
    }
};

/* SORTING METHOD */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count = 1, n = nums.size();
        vector<int> ans;
        
        sort(nums.begin(),nums.end());
        
        for (int i=1;i<n;i++) {
            if (nums[i-1] == nums[i]) { count++; }
            else {
                if (count > n/3) { ans.push_back(nums[i-1]); }
                count = 1;
            }
        }
        if (count > n/3) { ans.push_back(nums[n-1]); }
        
        return ans;
    }
};