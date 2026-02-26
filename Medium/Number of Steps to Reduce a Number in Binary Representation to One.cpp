#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Difficulty : Medium 

/* BINARY NUMBERS, BIT MANIPULATION  AND SIMULATION : DIVIDE BY 2 = LEFT SHIFT BY 1 BIT, ADDING 1 CREATES MORE LEFT SHIFTS BY MAKING NUMBER DIVISIBLE BY 2 */
class Solution {
public:
    int numSteps(string s) {

        int n = s.length(), i = n-1, ops = 0;

        while (i>0) {
            if (s[i] == '0') { i--; ops++; }
            else {
                ops++;
                while (i>=0 and s[i] == '1') { ops++; i--; }
                if (i>=0) { s[i] = '1'; }
            }
        }

        return ops;                               
    }
};