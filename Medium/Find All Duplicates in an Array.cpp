#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Difficulty : Medium

/* SORTING - Time : O(NlogN + N), Space : O(1) */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i=1;i<n;i++) {
            if (nums[i] == nums[i-1]) { ans.push_back(nums[i]); }
        }
        return ans;
    }
};

/* HASH SET - Time : O(N), Space : O(N) */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> hs;
        vector<int> ans;
        for (auto num : nums) {
            if (hs.find(num) != hs.end()) { ans.push_back(num); }
            else { hs.insert(num); }
        }
        return ans;
    }
};