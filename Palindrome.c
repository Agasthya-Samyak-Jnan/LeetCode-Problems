#include<stdio.h>
#include<stdbool.h>

//Link to the Problem: https://leetcode.com/problems/palindrome-number/
//Difficulty: Easy

bool isPalindrome(int x) {
    
    if (x < 0) { return false; }
    
    long r = 0, org = x;
    
    while (x > 0) {
      r  = (r*10) + (x % 10);
      x /= 10;
    }
    
    if (org == r) { return true; }
    return false;
}