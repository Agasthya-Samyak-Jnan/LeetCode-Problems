#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/next-greater-element-i/
// Difficulty : Easy

/* MONOTONIC STACK SOLUTION */
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            
            unordered_map<int,int> mp;
            stack<int> s;
            int m = nums1.size(), n = nums2.size();
    
            vector<int> nge(n,-1), ans;
    
            for (auto& i : nums1) { mp[i] = 1; }
    
            for (int i=0;i<n;i++) {
                if (mp[nums2[i]]) { mp[nums2[i]] = i; }
                while (!s.empty() and nums2[s.top()] < nums2[i]) {
                    nge[s.top()] = nums2[i];
                    s.pop();
                }
                s.push(i);
            }
    
            for (auto& i : nums1) {
                ans.push_back(nge[mp[i]]);
            }
    
            return ans;
        }
    };