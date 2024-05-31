#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/contains-duplicate/
// Difficulty: Easy

/* Sorting Solution */
class Solution {
public:
    inline bool containsDuplicate(vector<int>& a) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        sort(a.begin(),a.end());
        int n = a.size();
        for (int i=0;i<n-1;i++) {
            if (a[i] == a[i+1]) { return true; }
        }
        return false;
    }
};

/* Hash Map Solution */
class Solution {
public:
    inline bool containsDuplicate(vector<int>& a) {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        unordered_map<int,int> num;
        int n = a.size();
         for (int i=0;i<n;i++) {
             num[a[i]] += 1;
             if (num[a[i]] == 2) { return true; }
         }
        return false;
    }
};