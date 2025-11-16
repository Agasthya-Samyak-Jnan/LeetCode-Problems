#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s
// Difficulty: Medium

using namespace std;

/* 
    - If there are 'n' 1s in a all 1s substring, then number of 'k' length substrings possible in it are 'n-k+1' (Think and check why it is) 
    - All possible substring lengths in a 'n' length substring ranges from 1 to 'n'.
    - So, all possible substrings in a string of length 'n' is sum of 'n-k+1' for all 'k' values from 1 to 'n'. (Iterative summation)
    - Writing the summation we observe a few common terms among terms in the summation.
        - 'n+1' is present in all 'n' terms in summation.
        - 'k' is summed from 1 to 'n' in all negative terms in summation - which can be reduced and thought as subtracting sum of numbers from 1 to 'n' from total Sum.
    - Finally number of substrings in a string of length 'n' : 
        - substrs =  n*(n+1) - sum(1 to 'n')
        - substrs = n*(n+1) - (n*(n+1)/2) because sum of 1 to 'n' can be expressed as n*(n+1)/2
        - substrs = n*(n+1) / 2 (Reduced to Single Computation)
    - Add all possible substrings in each substring of 1s in the given string 's'.
*/

/* PURELY MATHEMATICAL */
class Solution {
public:
    int mod = 1e9 + 7;

    int substrs (int n) {
        int sum = 0;
        for (int k=1;k<=n;k++) { sum =  (sum + (n-k+1)) % mod; }
        return sum;
    }

    int numSub(string s) {
        
        int i = 0, _1slen = 0, count = 0;

        while (s[i]) {
            if (s[i] == '1') { _1slen++; }
            else { 
                count = (count + substrs(_1slen)) % mod;
                _1slen = 0; 
            }
            i++;
        }

        count = (count + substrs(_1slen)) % mod;

        return count;
    }
};

/* OPTMIZED BY REDUCTION FROM ITERATIVE SUMMATION TO SINGLE COMPUTATION */
class Solution {
public:
    int mod = 1e9 + 7;

    int substrs (long long n) { return (n*(n+1)/2) % mod; }

    int numSub(string s) {
        
        int i = 0, _1slen = 0, count = 0;

        while (s[i]) {
            if (s[i] == '1') { _1slen++; }
            else { 
                count = (count + substrs(_1slen)) % mod;
                _1slen = 0; 
            }
            i++;
        }

        count = (count + substrs(_1slen)) % mod;

        return count;
    }
};