#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/time-based-key-value-store/
// Difficulty : Medium

/* BINARY SEARCH + SYSTEM DESIGN - Store {timestamp,value} pairs per key and then binary search over timestamp intervals formed. */
class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> tp;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        tp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        int low = 0, high = tp[key].size() - 1, mid = 0;
        auto& key_arr = tp[key];

        while (low <= high) {
            mid = (low+high)/2;
            if (key_arr[mid].first <= timestamp) { low = mid+1; }
            else { high = mid-1; } 
        } 

        return high == -1 ? "" : key_arr[high].second;
    }
};