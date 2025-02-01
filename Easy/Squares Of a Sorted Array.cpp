#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/squares-of-a-sorted-array/
// Difficulty : Easy

/* COUNTING SORT */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int a[10001] = {0}, mn = INT_MAX, mx = INT_MIN;
        
        for (auto& i : nums) {
            a[abs(i)]++;
            mn = min(mn,abs(i));
            mx = max(mx,abs(i));
        }
        
        nums = {};
        
        for (int i=mn;i<=mx;i++) {
            while (a[i]) {
                nums.push_back(i*i);
                a[i]--;
            }
        }
        
        return nums;
    }
};