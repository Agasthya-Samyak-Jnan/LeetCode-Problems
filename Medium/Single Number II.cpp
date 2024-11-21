#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/single-number-ii/
// Difficulty : Medium 

/* There is a BIT MANIPULATION SOLUTION to this WITHOUT using EXTRA SPACE */

/* HASH TABLE METHOD (USING EXTRA SPACE)*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto i : nums) { 
            if (mp[i] < 2) { mp[i]++; }
            else { mp.erase(i); }
        }
        vector<int> ans;
        for (auto i : mp) { ans.push_back(i.first); }
        return ans[0];
    }
};