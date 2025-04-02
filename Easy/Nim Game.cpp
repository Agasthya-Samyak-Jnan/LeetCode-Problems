#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/nim-game/
// Difficulty : Easy

/* MATH - ALL NUMBERS THAT ARE MULTIPLES OF 4 WILL MAKE US LOSE IF PLAYED OPTIMALLY BY BOTH  AND WE ARE FIRST */
class Solution {
    public:
        bool canWinNim(int n, bool my_turn = true) {
            return n%4 != 0;
        }
};

/* RECURSION - INTUITION - TIME LIMIT EXCEEDED */
class Solution {
    public:
        bool canWinNim(int n, bool my_turn = true) {
            if (n < 4) { return my_turn; }
            if (my_turn) { return canWinNim(n-1,!my_turn) or canWinNim(n-2,!my_turn) or canWinNim(n-3,!my_turn); }
            return canWinNim(n-1,!my_turn) and canWinNim(n-2,!my_turn) and canWinNim(n-3,!my_turn);
        }
};