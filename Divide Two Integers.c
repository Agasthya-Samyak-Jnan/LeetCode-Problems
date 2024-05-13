#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>

// Divide Two Integers without using Division, Multiplication and Mod Operators.

// Link to the Problem: https://leetcode.com/problems/divide-two-integers/submissions/
// Difficulty: Medium

// Brute Force Approach: Repeated Subtraction Method (O(N))

/* Restore Division Computer Architecture Method (32-Bit Ranged) : Time Complexity: O(logN) [Bit Manipulation]
   *. Check for 0 in dividend or divisor, if so Return 0 directly.
      Check for strictly either negative dividend or negative divisor, if so final answer should be negative as well.
      Convert negative dividend and/or negative divisor to positive numbers before Division
   1. Intialiazation of Required Variables.
   2. Loop Below Steps from 3 to 6,if Bit Count greater than 0.
   3. Left Shift A,Q | Intialize first bit of A with Last Bit of Q.
   4. A = A - B
   5. if Sign Bit = 1 (A < 0) , then Set Quotient First Bit to 0 and do A = A + B.
      Otherwise, Set Quotient First Bit to 1.
   6. One Bit Completed, decrement Count by 1.
   7. After Looping completes, A = Remainder, ans = Quotient
   8. Check for Required Range allowed for Division (in this case, 32-Bit)
*/
int divide (long long q,long long b) {
    bool neg = 0;
    if (b == 0 || q == 0) { return 0; }
    if (q<0 ^ b<0) { neg=1; }
    if (q<0) { q = -q; }
    if (b<0) { b = -b; }

    long long a = 0;
    int n = log2(q) + 1;
    long long ans = 0;

    while (n > 0) {
        a = a<<1;
        if ((q>>(n-1))&1) { a = a|1<<0; }
        else { a = a&(~(1<<0)); }
        ans = ans<<1;
        a = a - b;
        if (a < 0) { ans = ans&(~(1<<0)); a = a + b; }
        else { ans = ans|(1<<0);}
        n--;
    }
    if (neg) { ans = -ans; }
    if (ans < INT_MIN ) { ans = INT_MIN; }
    if (ans > INT_MAX ) { ans = INT_MAX; }
    return ans;
}