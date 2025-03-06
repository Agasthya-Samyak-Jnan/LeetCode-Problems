#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/prime-palindrome/
// Difficulty : Medium 

/* OPTIMIZED BRUTE FORCE CHECKING */
class Solution {
    public:
        int primePalindrome (int num) {
    
            if (num < 3) { return 2; }

            while (1) {
                
                // Palindrome Check - First because there are less palindromes than primes.
                int rev = 0, n = num;
                while (n>0) {
                    rev = rev*10 + n%10;
                    n /= 10;
                }
                if (rev != num) { num++; continue; } // Don't check if its prime when it isn't a palindrome.
                
                // Prime Check 
                if (num%2 == 0) { num++; continue; }
                int i;
                for (i=3;i*i<=num;i+=2) {
                        if (num%i == 0) { break; }
                }
                if (i*i > num) { return num; }
    
                num++;
            }
    
            return num;
        }
};

