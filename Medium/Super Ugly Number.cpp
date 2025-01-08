#include<bits/stdc++.h>

using namespace std; 

// Link to the Problem : https://leetcode.com/problems/super-ugly-number/
// Difficulty : Medium 

/* RECURSION WITH MIN-HEAP PRIORITY QUEUE */
class Solution {
public:
    priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
    vector<int> p;

    int solve (int i) {
        if (i == 1) { return pq.top().first; }
        auto [num,factor] = pq.top(); pq.pop();
        for (auto i : p) { if (factor <= i) { pq.push({num*i,i}); } }
        return solve(i-1);
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        pq.push({1,primes.front()});
        p = primes;
        return solve(n);
    }
};
