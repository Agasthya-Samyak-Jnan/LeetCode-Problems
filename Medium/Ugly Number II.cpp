#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/ugly-number-ii/
// Difficulty : Medium 

/* RECURSION WITH MIN-HEAP PRIORITY QUEUE */
class Solution {
public:
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;

    int solve (int i) {
        if (i == 1) { return pq.top().first; }

        auto [num,factor] = pq.top(); pq.pop();
        // cout<<num<<","<<factor<<"\n";

        if (factor <= 2) { pq.push({num*2,2}); }
        if (factor <= 3) { pq.push({num*3,3}); }
        if (factor <= 5) { pq.push({num*5,5}); }
        
        return solve(i-1);
    }

    int nthUglyNumber(int n) {
        pq.push({1,2});
        return solve(n);
    }
};
