#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/can-i-win/
// Difficulty : Medium 

/* DYNAMIC PROGRAMMING SOLUTION USING BITMASK BASED ON MIN-MAX PHILOSOPHY FROM GAME THEORY since both players play optimally. */

/* 
    MIN-MAX PHILOSOPHY :
    - There are two players - MAX and MIN , MAX tries to WIN or make MAX win the game , MIN tries to defeat MAX or make MAX lose the game. 
    - MAX tries to "maximize minimum possible gain" or "minimize maximum possible loss" with respect to MAX.
    - MIN tries to "minimize maximum possible gain" or "maximize minimum possible loss" with respect to MAX.
*/

/* PURE RECURSION -TIME LIMIT EXCEEDED */
class Solution {
public:

    int target, limit;

    bool dfs (int sum, int turn, int nums) {
        if ((target-sum) <= limit and (nums>>(target-sum)) > 0) { return (turn == 0); }
        for (int i=1;i<=limit;i++) {
            if ((nums>>i)&1 == 1) {
                auto newnums = nums;
                newnums &= ~(1<<i);
                bool result = dfs(sum+i,(turn == 0),newnums);
                if (turn == 0 and result == true) { return true; } // if there is at least 1 chance for 1st player to win, they will play that. 1st Player wins this case.
                if (turn == 1 and result == false) { return false; } // if there is at least 1 chance for 2nd player to win, they will play that. 1st player loses thsi case.
            }
        }
        return (turn == 1); 
        // if out of loop when 2nd player's turn means no loss cases possible here hence 1st Player wins in this state.
        // if out of loop when 1st Player's turn means no win cases possible here hence 1st player loses in this state.
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        target = desiredTotal;
        limit = maxChoosableInteger;
        return dfs(0,0,pow(2,maxChoosableInteger+1)-2);
    }
};

/* RECURSION WITH 1D MEMOIZATION - NUMBER SELECTIONS STATUS (BITMASK SHOWING WHAT NUMBERS ARE SELECTED) AT EACH CALL IS A UNIQUE STATE */
class Solution {
public:

    int target, limit;
    unordered_map<int,int> dp;

    bool dfs (int sum, int turn, int nums) {
        if (dp.find(nums) != dp.end()) { return dp[nums]; }
        if ((target-sum) <= limit and (nums>>(target-sum)) > 0) { return dp[nums] = (turn == 0); }
        for (int i=1;i<=limit;i++) {
            if ((nums>>i)&1 == 1) {
                auto newnums = nums;
                newnums &= ~(1<<i);
                bool result = dfs(sum+i,(turn == 0),newnums);
                if (turn == 0 and result == true) { return dp[nums] = true; }
                if (turn == 1 and result == false) { return dp[nums] = false; }
            }
        }
        return dp[nums] = (turn == 1); // if out of loop when second player's turn means no loss cases possible hence
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        target = desiredTotal;
        limit = maxChoosableInteger;
        if (limit >= target) { return true; }
        int totalsum = (limit*(limit+1))/2;
        if (totalsum < target) { return false; } 
        return dfs(0,0,pow(2,maxChoosableInteger+1)-2);
    }
};