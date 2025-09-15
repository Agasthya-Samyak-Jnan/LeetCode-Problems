#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/first-bad-version/
// Difficulty : Easy    

/* BINARY SEARCH - IF A VERSION IS BAD, ALL VERSIONS BEYOND IT ARE ALSO BAD. */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        long long low = 1, high = n, mid;

        while (low <= high) {
            mid = (low+high)/2;
            if (isBadVersion(mid)) { high = mid-1; }
            else { low = mid+1; }
        } 
        
        return low;
    }
};