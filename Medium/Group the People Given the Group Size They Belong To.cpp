#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-eventual-safe-states/
// Difficulty : Medium 

/* HASH TABLE + GREEDY - FILL PEOPLE OF SAME GROUP SIZE TO A SINGLE GROUP UNTIL ITS SIZE BECOMES EQUAL TO SIZE OF GROUP PEOPLE IN IT BELONG TO. */
class Solution {
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            
            vector<vector<int>> ans;
            unordered_map<int,vector<int>> mp;
            int n = groupSizes.size();
    
            for (int i=0;i<n;i++) {
                mp[groupSizes[i]].push_back(i);
                if (mp[groupSizes[i]].size() == groupSizes[i]) { 
                    ans.push_back(mp[groupSizes[i]]);
                    mp[groupSizes[i]] = {};
                }
            }
    
            return ans;
        }
};