#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/single-number-iii/
// Difficulty : Medium 

/* There is a BIT MANIPULATION SOLUTION to this WITHOUT using EXTRA SPACE */

/* HASH TABLE METHOD (USING EXTRA SPACE)*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for (auto i : nums) {
            if (!mp[i]) { mp[i] = 1; }
            else { mp.erase(i); }
        }
        
        for (auto i : mp) { ans.push_back(i.first); }
        
        return ans;
    }
};