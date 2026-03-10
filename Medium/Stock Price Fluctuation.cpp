#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/stock-price-fluctuation/
// Difficulty : Medium

/* ORDERED CONTAINERS AND HASH TABLES */

/* ORDERED MULTSET VERSION */
class StockPrice {
public:
    unordered_map<int,int> t2p;
    multiset<int> prices;
    int now = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto temp = prices.find(t2p[timestamp]);
        if (temp != prices.end()) { prices.erase(temp); }
        now = max(now,timestamp);
        t2p[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return t2p[now];
    }
    
    int maximum() {
        return *(prices.rbegin());
    }
    
    int minimum() {
        return *(prices.begin());
    }
};

/* ORDERED MAP VERSION */
class StockPrice {
public:
    unordered_map<int,int> t2p;
    map<int,int> prices;
    int now = 0;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        int prev_price = t2p[timestamp];
        if (prices.find(prev_price) != prices.end()) { 
            prices[prev_price]--; 
            if (prices[prev_price] == 0) { prices.erase(prev_price); }
        }
        now = max(now,timestamp);
        t2p[timestamp] = price;
        prices[price]++;
    }
    
    int current() {
        return t2p[now];
    }
    
    int maximum() {
        return (*prices.rbegin()).first;
    }
    
    int minimum() {
        return (*prices.begin()).first;
    }
};