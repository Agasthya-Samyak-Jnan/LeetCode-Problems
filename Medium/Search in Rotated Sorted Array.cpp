#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty : Medium

/* Application of Binary Search Idea */
class Solution {
public:
    int search(vector<int>& a, int target) {
        
        int low = 0, high = a.size()-1;
        
        while (low <= high) {
            
            int mid = (low+high)/2;
            
            if (a[mid] == target) { return mid; }
            
            if (a[mid] >= a[low]) {
                if (a[low] <= target && target <= a[mid]) { high = mid-1; }
                else { low = mid+1; }
            }
            
            else {
                if (a[mid] <= target && target <= a[high]) { low = mid+1; }
                else { high = mid-1; }
            }
            
        }
        
        return -1;
    }
};