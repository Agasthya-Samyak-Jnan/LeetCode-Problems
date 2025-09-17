#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-winning-player-in-coin-game/
// Difficulty : Easy 

/* SIMULATION IS FIRST SOLUTION. USE BASIC MATH FOR DIRECT SOLUTION WITHOUT SIMULATION. */

/* SIMULATION */
class Solution {
public:
    string winningPlayer(int x, int y) {
        int turns = 0;
        while (x>=1 and y>=4) { x-=1; y-=4; turns++; }
        return (turns % 2 == 0) ? "Bob" : "Alice";
    }
};

/* BASIC MATH */
class Solution {
public:
    string winningPlayer(int x, int y) {
        if (y >= 4*x) {
            return (x % 2 == 0) ? "Bob" : "Alice";
        }
        return ((y/4) % 2 == 0) ? "Bob" : "Alice";
    }
};

/* OPTMIZED MATH */
class Solution {
public:
    string winningPlayer(int x, int y) {
        return (min(x,y/4) % 2 == 0) ? "Bob" : "Alice";
    }
};