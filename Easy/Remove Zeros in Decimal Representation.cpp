#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-zeros-in-decimal-representation/
// Difficulty : Easy

/* MATH */
class Solution {
public:
    long long removeZeros(long long n) {

        long long num = 0, base = 1;
        
        while (n>0) {
            if (n%10 > 0) { 
                num += base*(n%10); 
                base *= 10;
            }
            n /= 10;
        }

        return num;
    }
};