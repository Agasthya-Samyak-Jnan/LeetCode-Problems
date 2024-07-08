#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-unique-elements/
// Difficulty : Easy

/* TC : O(N) , SC : O(N) - Hash Map Method */
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size(), sum = 0;
        // Memorize Occurences of Numbers
        for (int i=0;i<n;i++) { mp[nums[i]]++; }
        // Only Add Numbers which Occured Only Once
        for (auto i : mp) { if (i.second == 1) { sum += i.first; } }

        return sum;
    }
};