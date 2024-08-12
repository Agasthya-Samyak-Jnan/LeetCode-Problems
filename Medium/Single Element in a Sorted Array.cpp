#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Difficulty : Medium

/* BINARY SEARCH : ODD-EVEN SIZED PARTITION SELECTION */
class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        
        int n = a.size();
        if (n == 1) { return a[0]; }
        int low = 0, high = n-1,mid;
        
        while (low < high) {
            
            mid = (low+high)/2;
            
            // Even Sized Partitions
            if (mid%2 == 0) {
               if ( (mid+1) < n && a[mid+1] == a[mid]) { low = mid+2; }
               else if ( (mid-1) >= 0 && a[mid-1] == a[mid]) { high = mid-2; }
               else { return a[mid]; }
            }
            
            // Odd Sized Partitions
            else {
                if (a[mid] == a[mid-1]) { low = mid+1; }
                else { high = mid-1; }
            }
        }
        
        return a[low];
    }
};