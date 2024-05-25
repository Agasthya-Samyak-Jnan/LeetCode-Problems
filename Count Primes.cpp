#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-primes/
// Difficulty : Medium

/* Time Complexity: O( N(1+log(log(N))) ) (Runtime 98ms, Top 97.1%) */
/* Best Solutions are TOO COMPLICATED TO UNDERSTAND, and Time Complexity of memset() is very less. */

class Solution {
public:
    int countPrimes(int n) {
        if (!n || n==1) { return 0; }
        int p=0;
        int prime[n];
        memset(prime,1,n*sizeof(int));
        for (int i=2;i<sqrt(n);i++) {
            if (prime[i]) {
              for (int j=i*i; j<n; j+=i) {
                   prime[j] = 0;
              }
            }
        }
        for (int i=2;i<n;i++) {
            if (prime[i]) { p++; }
        }
        return p;
    }
};