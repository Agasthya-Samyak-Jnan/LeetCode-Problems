#include<bits/stdc++.h>

using namespace std; 

// Link to the Problem : https://leetcode.com/problems/sort-colors/
// Difficulty : Medium

/* COUNTING SORT FOR 3 ELEMENTS {0,1,2} */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0};
        int n = nums.size();
        for (int i=0;i<n;i++) { arr[nums[i]]++; }
        nums.clear();
        for (int i=0;i<3;i++) {
            while (arr[i]) { nums.push_back(i); arr[i]--; }
        }     
    }
};