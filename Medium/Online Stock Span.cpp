#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/online-stock-span/
// Difficulty : Medium

/* THE IDEA OF INTERVALS - COUNT THROUGH INTERVALS - BRUTE FORCE OPTIMIZED IN A SMART WAY */
class StockSpanner {
public:

    vector<vector<int>> stocks; // {price,span}

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i = stocks.size()-1, span = 1;
        while (i>=0 and stocks[i][0] <= price) {
            span += stocks[i][1];
            i -= stocks[i][1];
        }
        stocks.push_back({price,span});
        return span;
    }
};