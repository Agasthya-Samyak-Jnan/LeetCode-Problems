#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/double-modular-exponentiation/
// Difficulty : Medium 

/* SIMULATION + MODULAR ARITHMETIC TECHNIQUES - DIVIDE AND CONQUER like strategy to compute of mod of large exponents - BINARY EXPONENTIATION. */
class Solution {
public:

    //  DIVIDE AND CONQUER based idea - BINARY EXPONENTIATION for numbers with large base and large exponent term
    int mod_exp (int base, int exp, int mod) {

        int result = 1;

        while (exp) {
            if (exp & 1) { result = (result * base) % mod; }
            exp = (exp>>1);
            base = (base * base) % mod;
        }

        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        
        int n = v.size();
        vector<int> good_indices;

        for (int i=0;i<n;i++) {
            int value = mod_exp(mod_exp(v[i][0],v[i][1],10),v[i][2],v[i][3]);
            if (value == target) { good_indices.push_back(i); }
        }

        return good_indices;
    }
};