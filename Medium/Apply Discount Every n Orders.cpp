#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/apply-discount-every-n-orders/
// Difficulty : Medium 

/* DESIGN + HASH TABLE */
class Cashier {
public:
    int n, discount, order_count;
    unordered_map<int,int> prod_price;

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        order_count = 0;
        this->n = n;
        this->discount = discount;
        int m = products.size();
        for (int i=0;i<m;i++) { prod_price[products[i]] = prices[i]; }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        order_count++;
        int m = product.size();
        double bill = 0;
        for (int i=0;i<m;i++) { bill += amount[i]*prod_price[product[i]]; }
        return (order_count % n == 0) ? bill*((100.0-discount)/100) : bill; 
    }
};

