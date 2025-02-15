#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/product-of-the-last-k-numbers/
// Difficulty : Medium

/* INITIAL INTUITIONS */
class ProductOfNumbers {
    public:
        vector<vector<int>> q;
    
        ProductOfNumbers() {}
        
        void add(int num) {
            q.push_back({num});
            int n = q.size();
            if (q.size() > 1) {
                for (auto& i : q[n-2]) { q.back().push_back(num*i); }
            }
        }
        
        int getProduct(int k) {
            return q.back()[k-1];
        }
};
    
class ProductOfNumbers {
    public:
        vector<int> q;
    
        ProductOfNumbers() {}
        
        void add(int num) {
    
            if (num == 0) { q = {}; }
            else {
                for (auto& i : q) { i *= num; }
                q.push_back(num);
            }
    
        }
        
        int getProduct(int k) {
            return q.size() < k ? 0 : q[q.size()-k];
        }
};

/* BEST SOLUTION */
class ProductOfNumbers {
    public:
        vector<int> q{1};

        ProductOfNumbers() {}
    
        void add(int num) {
            if (num != 0) { q.push_back(num * q.back()); }
            else {
                q.clear();
                q.push_back(1);
            }
        }
    
        int getProduct(int k) {
            return k < q.size() ? q.back() / q[q.size() - k - 1] : 0;
        }
};
    