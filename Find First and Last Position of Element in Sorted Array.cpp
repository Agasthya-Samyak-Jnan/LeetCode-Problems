#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Difficulty: Medium

/* Time Complexity: O( logN + first-occurence + last-occurence )  */
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int low=0,high=a.size(),n=high, mid;
        if(high==0) {return {-1,-1}; }
        int i=-1,j=-1;
        while (low<=high) {
            mid = (low+high)/2;
            if (mid >= n) { break; }
            if (a[mid] == target) { i=mid, j=mid; break; }
            if (a[mid] < target) { low = mid+1; }
            else { high = mid-1; }
        }
        if (i==-1) { return {i,j}; }
        while (i>=0 && a[i] == a[mid]) { i--; }
        while (j<n && a[j] == a[mid]) { j++; }
        return {i+1,j-1};
    }
};