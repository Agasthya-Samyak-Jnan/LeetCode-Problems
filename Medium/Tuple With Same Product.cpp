#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/tuple-with-same-product/
// Difficulty : Medium

/* BASIC INTUITION */
class Solution {
public:
    // unordered_map<long,long> FACT;

    // long fact (long i) {
    //     if (FACT.find(i) != FACT.end()) { return FACT[i]; }
    //     return i <= 1 ? 1 : i*fact(i-1);
    // }

    long tupleSameProduct(vector<int>& nums) {
        
        unordered_map<long,long> mp;
        int n = nums.size();
        long ans = 0;

        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                mp[nums[i]*nums[j]]++;
            }
        }

        // for (auto& i : mp) {
        //     if (i.second > 1) { ans += (fact(i.second)/(2*fact(i.second-2)))*8; }
        // }

        for (auto& i : mp) {
            if (i.second > 1) { ans += (i.second*(i.second-1)/2)*8; }
        }

        return ans;
    }
};