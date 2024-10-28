#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-square-streak-in-an-array/
// Difficulty : Medium

// USING COUNTING SORT (HASH TABLE METHOD)
int longestSquareStreak (vector<int>& nums) {

    int a[100001] = {0}, mx = INT_MIN, mn = INT_MAX, max_len = -1, curr_len;

    for (int i : nums) { 
        mx = max(mx,i);
        mn = min(mn,i);
        a[i]++; 
    }

    for (int i=mn;i<=mx;i++) {
        long long j = i;
        curr_len = 0;
        while (j <= mx  && a[j]) { curr_len++; j = j*j; }
        max_len = curr_len > 1 ? max(max_len,curr_len) : max_len;
    }

    return max_len;
}

int main () {
    vector<int> nums = {3,3,6,6,5,2};
    cout<<longestSquareStreak(nums);
    return 0;
}