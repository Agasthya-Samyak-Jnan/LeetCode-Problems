#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-missing-and-repeated-values/
// Difficulty : Easy

/* HASH TABLE METHOD */
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
            
            int repeated = 0, n = g.size()*g[0].size(), missing = (n*(n+1))/2; 
            unordered_map<int,int> mp;
    
            for (auto& i : g) {
                for (auto& j : i) {
                    if (mp[j]) { repeated = j; }
                    else { mp[j] = 1; }
                    missing -= j;
                }
            }
    
            missing += repeated;
    
            return {repeated,missing};
        }
};