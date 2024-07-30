#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty : Easy

/* Intuition is to Keep BUY_PRICE MINIMUM , SELL_PRICE MAXIMUM BUT INDEX OF BUY DAY SHOULD BE LESSER THAN SELL DAY. */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(),maximum = 0, buy_at = prices[0];
        
        for (int i=1;i<n;i++) {
            if (buy_at > prices[i]) {
                buy_at = prices[i];
            }
            maximum = max(maximum,prices[i]-buy_at);
        }
        
        return maximum;
    }
};