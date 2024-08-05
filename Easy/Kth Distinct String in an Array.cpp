#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-distinct-string-in-an-array/
// Difficulty : Easy

/* HASH TABLE METHOD - MEMORIZE HOW MANY TIMES EACH STRING OCCURS FOR EASY UNIQUENESS CHECK */
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,int> mp;
        
        for (auto i : arr) { mp[i]++; }
        
        for (auto i : arr) { if (mp[i] == 1 && --k == 0) { return i; } }
        
        return "";
    }
};