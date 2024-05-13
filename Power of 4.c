#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Link to the Problem: https://leetcode.com/problems/power-of-four/
// Difficulty : Easy

// NOTE: I haven't found any Math Optimizations on this one.

// Brute Force: Time Complexity: O(log4(N)) 
bool isPowerOfFour(int n) {
     if (n <= 0) { return 0; }
     while (!(n%4)) { n /= 4; }
     if (n == 1) { return 1; }
     return 0;
}
