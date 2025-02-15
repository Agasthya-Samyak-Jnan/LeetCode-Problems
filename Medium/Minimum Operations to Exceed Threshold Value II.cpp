#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
// Difficulty : Medium

/* PRIORITY QUEUE (MIN HEAP) + SIMULATION */
class Solution {
    public:
        long long minOperations(vector<int>& nums, int k) {
            
            priority_queue<long long,vector<long long>,greater<long long>> pq;
            long long x,y,operations = 0;
    
            for (auto i : nums) { pq.push(i); }
    
            while (1) {
                while (!pq.empty() and pq.top() >= k) { pq.pop(); }
                if (pq.empty()) { break; }
                x = pq.top(); pq.pop();
                y = pq.top(); pq.pop();
                pq.push(2*min(x,y)+max(x,y));
                operations++;
            }
    
            return operations;
        }
};