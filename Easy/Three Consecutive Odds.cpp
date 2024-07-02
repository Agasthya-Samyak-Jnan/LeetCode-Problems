#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/three-consecutive-odds/
// Difficulty : Easy

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
         int n = arr.size(), odds = 0;
         for (int i=0;i<n;i++) {
             if (arr[i]%2 != 0) { odds++; }
             else { odds = 0; }
             if (odds == 3) { return true; }            
         }
         return false;
    }
};