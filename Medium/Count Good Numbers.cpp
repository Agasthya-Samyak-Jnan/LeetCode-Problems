#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-good-numbers/
// Difficulty : Medium


/* MATH - PERMUTATIONS (COUNTING THEORY) + PROPERTIES OF MODULUS + BINARY MODULAR EXPONENTIATION */
class Solution {
    public:
    
        /* DIVIDE AND CONQUER - BINARY MODULAR EXPONENTIATION - O(log(exp)) Time Complexity */
        long long mod_exp (long long base, long long exp, long long mod) {
    
            long long ans = 1;
            base = base % mod;
    
            while (exp > 0) {
                if ((exp&1) == 1) { ans = (ans * base) % mod; }
                base = (base * base) % mod;
                exp = exp>>1;
            }
    
            return ans;
        }
    
        /* Counting Theory */
        /* According to Question :
            - You can take 0,2,4,6,8 for even positions - 5 possibilities per position.
            - You can take 2,3,5,7 for odd positions - 4 possibilities per position.
            - If there are 'n' digits, 
                - if 'n' is even, then n/2 positions are odd positions and n/2 positions are even positions.
                Hence, all possible arrangements = 5^(n/2) * 4^(n/2) = 20^(n/2)
    
                - if 'n' is odd, then n/2 positions are odd positions and (n/2)+1 positions are even 
                positions.
                Hence, all possible arrangements = 5^((n/2)+1) * 4^(n/2)
    
                Take modulus of final product to avoid overflow.
        */
        int countGoodNumbers(long long n) {
    
            long long mod = 1e9 + 7;
    
            if (n%2 == 0) { return mod_exp(20,n/2,mod); }
            return ( mod_exp(5,(n/2)+1,mod) * mod_exp(4,n/2,mod) ) % mod;
            
        }
};