#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Link to the Problem : https://leetcode.com/problems/power-of-three/
// Difficulty : Easy

/* Clue to Best Solution for Power of 'm' problems : 
   1. Find Highest Power of 'm' under given Range (Here->2^31)
   2. Return true if given number is non-negative and perfectly 
      divides highest power of 'm' under given Range.

   Reason of Logic: Any power of 'm' is always perfectly divisible by 
                    powers of 'm' smaller than itself,
                    ONLY FOR NUMBERS THAT ARE NOT POWERS OF ANY OTHER
                    NUMBERS i.e UNIQUE BASE NUMBERS. 
*/

// Brute Force: Time Complexity: O(log3(N)) 
bool isPowerOfThree(int n) {
     if (n <= 0) { return 0; }
     while (!(n%3)) { n /= 3; }
     if (n == 1) { return 1; }
     return 0;
}

// Math Optimization: Time Complexity: O(1) 
bool isPowerOfThree(int n) {
     return n>0 && (!(1162261467%n));
}
