#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/k-th-smallest-prime-fraction/
// Difficulty : Medium 

/* USING PRIORITY QUEUE (MIN HEAP) - O(2*(N^2logN)) TIME , O(N^2) TIME */

// Compare and sort the heap by Fraction Value of Pair of Numbers - Minimum Fraction on Top
struct comp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return ((double)a[0]/(double)a[1]) > ((double)b[0]/(double)b[1]);
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<vector<int>,vector<vector<int>>,comp> pq;
        int n = arr.size();

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                pq.push({arr[i],arr[j]});
            }
        }

        while (k>1) {
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};