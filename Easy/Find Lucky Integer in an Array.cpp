#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Difficulty : Easy 

/* HASH TABLE + COUNTING */
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int largestLuckyInteger = -1;  
        unordered_map<int,int> mp;
        for (auto num : arr) { mp[num]++; } 
        for (auto p : mp) {
            if (p.first == p.second and p.first > largestLuckyInteger) {
                largestLuckyInteger = p.first;
            }
        }
        return largestLuckyInteger;
    }
};