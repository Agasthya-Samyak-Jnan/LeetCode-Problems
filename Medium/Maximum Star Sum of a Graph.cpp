#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-star-sum-of-a-graph/
// Difficulty : Medium 

/* HOW TO FLEX YOUR PRIORITY QUEUE SKILLS + GRAPH and SOME INTUITION */

class Solution {
public:
    int maxStarSum(vector<int>& val, vector<vector<int>>& edges, int k) {

        int n = val.size();
        vector<priority_queue<int>> g(n);
        priority_queue<int> bestSum;

        for (auto e : edges) {
            g[e[0]].push(val[e[1]]);
            g[e[1]].push(val[e[0]]);
        }

        for (int i=0;i<n;i++) {
            int maxedges = k, sum = val[i];
            while (!g[i].empty() and maxedges and g[i].top() > 0) {
                sum += g[i].top(); g[i].pop();
                maxedges--;
            }
            bestSum.push(sum);
        }

        return bestSum.top();
    }
};