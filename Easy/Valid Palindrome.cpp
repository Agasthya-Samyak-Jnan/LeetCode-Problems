#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-palindrome/
// Difficulty : Easy

/* TWO POINTERS */
class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.length(), i = 0, j = n-1;
        char a,b;
        
        while (i<j) {
            
            // Skip Over Non-Alphanumeric Characters
            while (i<n && !isalnum(s[i])) { i++; }
            while (j>=0 && !isalnum(s[j])) { j--; }
            
            if (i>=n || j<0 || i>j) { break; }
            
            // Case-insensitive Comparison of Characters
            a = (s[i] >= 97) ? s[i] : (s[i]+32);
            b = (s[j] >= 97) ? s[j] : (s[j]+32);
            if (a != b) { return false; }
            
            // Traverse the String
            i++; j--;
        }
        
        return true;
    }
};