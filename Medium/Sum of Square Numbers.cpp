#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-square-numbers/
// Difficulty : Medium 

/* BRUTE FORCE METHOD */
class Solution {
public:
    bool judgeSquareSum(long c) {
        
        long k = sqrt(c);
        if (k*k == c) { return true; }
        
        for (long i=1;i<=k;i++) {
            for (long j=1;j<=k;j++) {
                if (i*i + j*j == c) { return true; }
            }
        }
        
        return false;
    }
};

/* MATHEMATICAL APPROACH :
 a^2 + b^2 = c , Fix 'a', 
then c - a^2 = b^2 => c - a^2 must be a square number to prove 'c' is a sum of squares. 
*/
bool is_square (long c) {
    long k = sqrt(c);
    return (k*k == c);       
}

class Solution {
public:
    bool is_square (long c) {
        long k = sqrt(c);
        return (k*k == c);       
    }
    
    bool judgeSquareSum(long c) {
        
        long k = sqrt(c);
        
        for (long i=0;i<=k;i++) {
            if (is_square(c - i*i)) { return true; }
        }
        
        return false;
    }
};

/* BINARY SEARCH with TWO POINTERS */
class Solution {
public:

    bool judgeSquareSum(long c) {
        
        long i = 0;
        long j = sqrt(c);
        
        while (i<=j) {
            long sum = i*i + j*j;
            if (sum == c) { return true; }
            if (sum < c) { i++; }
            else { j--; }
        }
        
        return false;
    }
};

