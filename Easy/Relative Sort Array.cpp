#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/relative-sort-array/
// Difficulty : Easy

/* Hash Map + Counting Sort with Constraints */
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int,int> mp;
        int m = arr1.size(), n = arr2.size();
        int maximum = 0;
        
        for (int i=0;i<n;i++) { mp[i] = arr2[i]; }
        
        vector<int> count_sort_arr(1001,0); // Constraint on Numbers in input = 1000
        for (int i=0;i<m;i++) { count_sort_arr[arr1[i]] += 1; maximum = max(maximum,arr1[i]); }
        
        arr1.clear();
        for (int i=0;i<n;i++) {
            while (count_sort_arr[mp[i]]) {
                arr1.push_back(mp[i]);
                count_sort_arr[mp[i]]--;
            }
        }
        
        for (int i=0;i<=maximum;i++) {
            while (count_sort_arr[i]) {
                arr1.push_back(i);
                count_sort_arr[i]--;
            }
        }
        
        return arr1;
    }
};