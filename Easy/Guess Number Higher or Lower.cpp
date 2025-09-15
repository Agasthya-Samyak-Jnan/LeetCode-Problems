#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/guess-number-higher-or-lower/
// Difficulty : Easy    

/* BINARY SEARCH - IF OUR NUMBER HIGHER THAN THIERS, GO TO LOWER HALF, OTHERWISE GO TO HIGHER HALF. */

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long low = 1, high = n, mid;

        while (low <= high) {
            mid = (low+high)/2;
            if (guess(mid) == 0) { return mid; }
            else if ( guess(mid) == -1) { high = mid-1; }
            else { low = mid+1; }
        }

        return -1;
    }
};