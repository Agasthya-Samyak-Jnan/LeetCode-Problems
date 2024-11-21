#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty : Medium

/* HASH TABLE + HASH TABLE METHOD - FREQUENCY TO NUMBER AND NUMBER TO FREQUENCY MAPPING */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,unordered_map<int,int>> freq;
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        
        for (int i=0;i<n;i++) {
            int f = mp[nums[i]];
            if (f != 0) { freq[f].erase(nums[i]); } 
            f = ++mp[nums[i]];
            freq[f][nums[i]] = 1;
        }
        
        for (auto it = freq.rbegin(); it != freq.rend(); it++) {
            for (auto& i : it->second) {
                ans.push_back(i.first);
                k--;
                if (k == 0) { return ans; } 
            }
        }
        
        return ans;
    }
};

/* HASH TABLE + PRIORITY QUEUE (MAX HEAP) METHOD - COUNT FREQUNECY , PUT IT INTO HEAP , EXTRACT K ELEMENTS FROM HEAP. */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for (auto& num : nums) { mp[num]++; }
        
        for (auto& i : mp) { pq.push({i.second,i.first}); }
        
        while (k) { ans.push_back(pq.top().second); pq.pop(); k--; }
                        
        return ans;
    }
};