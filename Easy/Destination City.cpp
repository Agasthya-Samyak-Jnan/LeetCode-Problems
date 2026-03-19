#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/destination-city/
// Difficulty : Easy

/* HASH SETS - COMPUTING SET DIFFERENCE IN ONE PASS */
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> CO, AC;  // Cities with Outgoing paths = CO, All Cities = AC

        // What we are doing is removing cities with outgoing paths from all cities set. Only destination city will be left. (1 city according to constraints)
        for (auto& path : paths) {
            CO.insert(path[0]);
            AC.insert(path[1]);
            AC.erase(path[0]);
            if (CO.find(path[1]) != CO.end()) { AC.erase(path[1]); }
        }
        
        return *AC.begin(); // AC = AC - CO (Set Difference)
    }
};