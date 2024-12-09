#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/prime-pairs-with-target-sum/
// Difficulty : Medium 

/* PRIME NUMBERS IN NUMBER THEORY - SIEVE OF ERATHOSTHENES */
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        
        int prime[1000001];
        memset(prime,1,sizeof(prime));
        vector<vector<int>> ans;
        
        for (int i=2;i*i<n;i++) {
            if (prime[i]) {
                for (int j=i*i;j<=n;j+=i) {
                    prime[j] = 0;
                }
            }
        }
        
        for (int i=2;i<=n/2;i++) {
            if (prime[i] && prime[n-i]) { ans.push_back({i,n-i}); }
        }
        
        return ans;
    }
};