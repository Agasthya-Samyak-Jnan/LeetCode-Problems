#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// Difficulty : Easy

/* BRUTE FORCE */
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> discount_prices;
        int n = prices.size();
        
        for (int i=0;i<n;i++) {
            int j=i+1;
            while (j<n and prices[j]>prices[i]) { j++; }
            if (j<n) { discount_prices.push_back(prices[i]-prices[j]); }
            else { discount_prices.push_back(prices[i]); }
        }

        return discount_prices;
    }
};

/* USING STACK (MONOTONIC STACK) */
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> discount_prices = prices;
        int n = prices.size();
        stack<int> s;
        
        for (int i=0;i<n;i++) {
            if (s.empty() or prices[s.top()] < prices[i]) { s.push(i); }
            else {
                while (!s.empty() and prices[s.top()] >= prices[i]) {
                    discount_prices[s.top()] -= prices[i];
                    s.pop();
                }
                s.push(i);
            }
        }

        return discount_prices;
    }
};