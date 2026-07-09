#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-array-is-good/
// Difficulty : Easy

/* HASH SET */
class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size(), mx = 0;

        for (auto num : nums) { mx = max(mx,num); }

        unordered_multiset<int> hs;

        for (int i=1;i<=mx;i++) { hs.insert(i); }
        hs.insert(mx);

        for (auto num : nums) {
            auto it = hs.find(num);
            if (it != hs.end()) { hs.erase(it); }
            else { return false; }
        }

        return hs.empty();        
    }
};

/* SORTING */
class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size(), mx = 0;

        for (auto num : nums) { mx = max(mx,num); }

        if (n != mx+1) { return false; }

        vector<int> base;

        for (int i=1;i<=mx;i++) { base.push_back(i); }
        base.push_back(mx);

        sort(nums.begin(),nums.end());

        for (int i=0;i<n;i++) {
            if (nums[i] != base[i]) { return false; }
        }

        return true;        
    }
};