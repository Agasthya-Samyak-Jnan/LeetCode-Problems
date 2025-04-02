#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/super-pow/
// Difficulty : Medium 

/* MATH : MODULAR ARITHMETIC THEOREMS + DIVIDE AND CONQUER (Recursive or Iterative) */
class Solution {
    public:
    
        /* DIVIDE AND CONQUER - Modular Exponentiation - Squaring Method (from Modular Arihtmetic and Cryptography) */
        /*
           Modular Multiplication : (a*b) mod p = ((a mod p)*(b mod p)) mod p 
           Using above, (a^x) mod p = (((a^y) mod p)*((a^z) mod p)) mod p - Where, x = y + z hence a^x * a^y = a^z.
        */
        long long modPow (long long base, long long exp, long long mod) {
    
            long long ans = 1;
            base = base % mod; // Avoid Overflow, before this number gets Sqaured below.
    
            while (exp > 0) {
                if ((exp & 1) == 1) { ans = (ans*base) % mod; } 
                exp = exp>>1;
                base = (base*base)%mod;
            }
    
            return ans;
        }
    
        /* 
            Euler's Theorem : 
                (a^b) mod p = (a^(b mod phi(p)) mod p), where phi(p) is Euler's Totient Function.
                phi(p) is defined as p-1 if 'p' is a prime, otherwise its number of 'Numbers' that are Co-Prime to 'p' from 1 till itself.
        */
        long long superPow(int a, vector<int>& b) {
    
            if (a == 1) { return 1; }
    
            long long exp = 0, phi_mod = 1140, mod = 1337;
    
            for (int& i : b) { exp = (exp*10 + i) % phi_mod; } 
            if (exp == 0) { exp = phi_mod; }
    
            return modPow(a,exp,mod);
        }   
};