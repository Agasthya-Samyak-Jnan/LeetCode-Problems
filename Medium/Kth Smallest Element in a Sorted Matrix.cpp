#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Difficulty : Medium 

/* TC : (n*n)*log(n*n) + k*log(n*n) - Min Heap - Unnecessary Solution */
class Solution {
public:
    int n=0;
    
    void min_heapify_up (vector<int>& a, int i) {
        while (i>0) {
            if (a[i] < a[(i-1)/2]) { 
                swap(a[i],a[(i-1)/2]);
                i = (i-1)/2;
            }
            else { break; }
        }
    }
     
    void min_heapify_down (vector<int>& a, int i) {
        while (1) {
            int k = i;
            if (2*i+1 < n && a[2*i+1] < a[k]) { k = 2*i+1; }
            if (2*i+2 < n && a[2*i+2] < a[k]) { k = 2*i+2; }
            if (k != i) { swap(a[i],a[k]); i=k; }
            else { break; }
        }
    }
    
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        vector<int> h;
        
        for (auto i : m) {
            for (auto j : i) {
                n++;
                h.push_back(j);
                min_heapify_up(h,n-1);
            }
        }
        k--;
        
        while (k) {
            swap(h[0],h[n-1]);
            n--; k--;
            min_heapify_down(h,0);
        }
        
        return h[0];
    }
};

/* TC : (n*n) + (n*n)log(n*n) - Conversion to Sorted Array - Intuition */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        vector<int> a;
        
        for (auto i : m) {
            for (auto j : i) {
                a.push_back(j);
            }
        }
        
        sort(a.begin(),a.end());
        
        return a[k-1];
    }
};

/* TC : (n*n)*log(k) - Max Heap - Best Solution (Running Queue of 'k' Smallest elements) */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        
        priority_queue<int> p;
        
        for (auto i : m) {
            for (auto j : i) {
                if (p.size() < k) { p.push(j); }
                else if (p.top() >= j) { p.pop(); p.push(j); }
            }
        }
    
        return p.top();
    }
};