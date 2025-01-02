#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-cost-for-tickets/
// Difficulty : Medium

/* TABULATION - DYNAMIC PROGRAMMING */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        
        vector<int> dp (400,INT_MAX);
        int final_day = days.back();
        unordered_set<int> day(days.begin(),days.end());

        dp[0] = 0;

        for (int i=1;i<=final_day;i++) {
            if (day.find(i) != day.end()) {
                dp[i] = min({dp[i-1]+cost[0],dp[max(0,i-7)]+cost[1],dp[max(0,i-30)]+cost[2]});
            }
            else { dp[i] = dp[i-1]; }
        }
        
        return dp[final_day];
    }
};