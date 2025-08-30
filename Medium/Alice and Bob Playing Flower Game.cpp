#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/alice-and-bob-playing-flower-game/
// Difficulty : Medium 

/* BASIC MATHS KNOWLEDGE AND SOME COMMON SENSE IS ENOUGH TO SOLVE THIS ONE */

/* BRUTE  FORCE */
class Solution {
public:
    long long flowerGame(int n, int m) {

        long long winCases = 0;
        
        for (int x=1;x<=n;x++) {
            for (int y=1;y<=m;y++) {
                if ((x+y) % 2 == 1) {
                    winCases++;
                }
            }
        }

        return winCases;
    }
};

/* PURELY MATHEMATICAL AND COMMON SENSE BASED IDEA */
class Solution {
public:
    long long flowerGame(long n, long m) {

        // The concept of "lanes" in this question is unnecessary due to way rules of this game works.
        // If Alice plays first, and Alice needs to Win, there should be a Total of Odd Number of Flowers. Think Why by simulating few cases.
        // Odd Number is always formed by Addition of an Even Number with an Odd Number.
        // Number of Odd Numbers in Range [1,x] is (x//2 + (add 1 if x is odd otherwise add 0)) Numbers.
        // Number of Even Numbers in Range [1,x] is (x//2) Numbers.

        return ((n/2)+(n%2==1))*(m/2) + (n/2)*((m/2)+(m%2==1));

    }
};