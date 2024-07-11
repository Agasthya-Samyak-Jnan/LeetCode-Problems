#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/range-sum-query-immutable/
// Difficulty : Easy

/* Prefix Sum - Create Array with Sum upto 'i' in a[i]. */
class NumArray {
public:
    vector<int> a;
    int n;
    
    NumArray(vector<int>& nums) {
        a = nums;
        n = a.size();
        for (int i=1;i<n;i++) { a[i] += a[i-1]; }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? a[right] : a[right] - a[left-1];
    }
};