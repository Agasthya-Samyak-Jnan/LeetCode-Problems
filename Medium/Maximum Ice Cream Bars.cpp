#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-ice-cream-bars/
// Difficulty : Medium

/* COUNTING SORT - HASH TABLE METHOD */
class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            
            int cs[100001] = {0}, mn = INT_MAX, mx = INT_MIN, bars = 0;
    
            for (auto& cost : costs) {
                cs[cost]++;
                mn = min(cost,mn);
                mx = max(cost,mx);
            }
    
            for (int cost=mn;cost<=mx and coins>=cost;cost++) {
                while (cs[cost] and coins >= cost) {
                    bars++;
                    coins -= cost;
                    cs[cost]--;
                } 
            }
    
            return bars;
        }
};

/* PRIORITY QUEUE - MIN HEAP METHOD */
class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {

        priority_queue<int,vector<int>,greater<int>> pq;
        int bars = 0;

        for (auto& cost : costs) { pq.push(cost); }

        while (!pq.empty() and coins >= pq.top()) {
            coins -= pq.top();
            pq.pop();
            bars++;
        }
            
        return bars;
    }
};

/* SORTING METHOD */
class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {

        int bars = 0, n = costs.size();

        sort(costs.begin(),costs.end());

        for (int i=0;i<n and coins>=costs[i];i++) {
            coins -= costs[i];
            bars++;
        }
            
        return bars;
    }
};