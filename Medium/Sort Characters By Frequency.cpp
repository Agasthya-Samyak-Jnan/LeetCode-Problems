#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-characters-by-frequency/
// Difficulty : Medium 

/* HASH TABLE + PRIORITY QUEUE (MAX HEAP) */
class Solution {
    public:
        string frequencySort(string s) {
            
            unordered_map<char,int> mp;
            priority_queue<pair<int,char>> pq;
    
            for (auto c : s) { mp[c]++; }
            for (auto p : mp) { pq.push({p.second,p.first}); }
    
            s = "";
    
            while (!pq.empty()) {
                auto [count,c] = pq.top(); pq.pop();
                while (count) {
                    s += c;
                    count--;
                }
            }
    
            return s;
        }
};