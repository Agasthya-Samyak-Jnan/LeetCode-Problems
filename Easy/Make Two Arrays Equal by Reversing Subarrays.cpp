#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
// Difficulty : Easy

/*  LOOK AT CONSTRAINTS - CHECKING IF FREQUENCY OF EVERY NUMBER IN BOTH ARRAYS IS EQUAL OR NOT - HASH TABLE */
/* TC : O(n) , SC : O(1) [ Constant Table Size of 1001 ] */
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
         int count[1001];
         memset(count,0,sizeof(count));
         int n = arr.size(), maximum = 0;
        
         for (int i=0;i<n;i++) {
             count[target[i]]++;
             count[arr[i]]--;
             maximum = max(maximum,target[i]);
             maximum = max(maximum,arr[i]);
         }
        
         for (int i=0;i<=maximum;i++) {
             if (count[i] != 0) { return false; }
         }
         
         return true;
    }
};