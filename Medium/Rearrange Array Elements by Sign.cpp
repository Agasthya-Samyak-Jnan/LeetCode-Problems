#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Difficulty : Medium 

/* SIMULATION + TWO POINTERS */

/* 2-PASS TIME + 3-ARRAY SPACE - BRUTE FORCE */
class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            
            int n = nums.size();
            vector<int> pos, neg, ans;
    
            for (int& i : nums) {
                if (i > 0) { pos.push_back(i); }
                else { neg.push_back(i); }
            }
    
            int i = 0, j = 0;
            while (j<n/2) {
                if (i <= j) { ans.push_back(pos[i]); i++; }
                else { ans.push_back(neg[j]); j++; }
            }
    
            return ans;
        }
};

/* 1-PASS TIME + 1-ARRAY SPACE - TWO POINTERS - OPTIMISED */
class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            
            int n = nums.size(), pos = 0, neg = 1; 
            vector<int> ans(n);
    
            for (int& num : nums) {
                if (num > 0) { ans[pos] = num; pos += 2; }
                else { ans[neg] = num; neg += 2; }
            }
            
            return ans;
        }
};