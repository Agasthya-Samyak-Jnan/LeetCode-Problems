#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/relative-ranks/
// Difficulty : Easy

/* This Problem can also be solved by SORTING the "ARRAY of PAIRS" formed after tagging Each Score with thier Indices. */

/* PRIORITY QUEUE - MIN HEAP METHOD */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size(),i;
        vector<string> ans(n);
        priority_queue<pair<int,int>> pq;
        
        for (i=0;i<n;i++) { pq.push({score[i],i}); }
        
        int pos = 0;
        while (!pq.empty()) {
            i = pq.top().second;
            pq.pop();
            
            if (pos > 2) { ans[i] = to_string(pos+1); }
            else if (pos == 0) { ans[i] = "Gold Medal"; }
            else if ( pos == 1) { ans[i] = "Silver Medal"; }
            else { ans[i] = "Bronze Medal"; }
            
            pos++;
        }
        
        return ans;
    }
};