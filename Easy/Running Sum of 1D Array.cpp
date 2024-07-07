#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/running-sum-of-1d-array/
// Difficulty : Easy

/* Simple and Intuitive Solution - (You can use TRIE as well if you want to remember these prefix sums in long run)*/
class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        int n = arr.size();
        for (int i=1;i<n;i++) { arr[i] = arr[i] + arr[i-1]; }
        return arr;
    }
};