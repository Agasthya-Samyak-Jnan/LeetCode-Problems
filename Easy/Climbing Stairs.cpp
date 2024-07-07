#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/climbing-stairs/
// Difficulty : Easy 

/* DYNAMIC PROGRAMMING :
   
   Try to Solve Many MINI problems of a Given Problem simultaneously (i.e in Runtime, "Dynamic") by dividing Problem into
   needed MINI problems.
    
   *1. Detect Subproblems : How to Reach Last Step? From (Last Step - 1) and (Last Step - 2). 
                            How to Reach those (Last Step - 1) and (Last Step -2)? 
                            For (Last Step - 1) , we can go from ((Last Step - 1) - 1) and ((Last Step - 1) - 2)
                            For (Last Step - 1) , we can go from ((Last Step - 2) - 1) and ((Last Step - 2) - 2)
                            RECURSION FOUND! ( needs some Practice to detect these patterns )

   *2. Find and Formulate Recurrence Relation : ways(n) = ways(n-1) + ways(n-2) [ways(n) = ways to get to 'nth' step]
   
   1. Recursive Solution - From Recurrence Relation.
   2. Recursive to Memoized-Recursive Solution.
   3. Memoized-Recursive to Memoized-Iterative Solution.
   4. (OPTIONAL) Memoized-Iterative to Iterative Solution.


*/

/* 1. Recursive Solution (Exponential Time + Exponential Recursion Call Stack Space) - Time Limit Exceeded */
class Solution {
public:
    int climbStairs(int n) {       
        if (n == 0 || n == 1) { return 1; }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

/* 2. Memoized-Recursive Solution (Linear Time + Linear Space + Recursion Call Stack Space) - 0ms Runtime */
class Solution {
public:
    int dp[46];
    
    Solution () { memset(dp,0,sizeof(dp)); dp[1] = 1, dp[2] = 2; }
    
    int climbStairs(int n) {
        if (n == 1 || n == 2) { return n; }
        if (dp[n-1] == 0) { dp[n-1] = climbStairs(n-1); }
        if (dp[n-2] == 0) { dp[n-2] = climbStairs(n-2); }
        dp[n] = dp[n-1] + dp[n-2];
        return dp[n];
    }
};

/* 3. Memoized-Iterative Solution (Linear Time - Linear Space) - 0ms Runtime */
class Solution {
public: 
    int climbStairs(int n) {
        int dp[46];
        dp[1] = 1, dp[2] = 2;
        for (int i=3;i<=n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

/* Constant_Space-Iterative Solution (Linear Time - Constant Space) - 2ms Runtime */
class Solution {
public: 
    int climbStairs(int n) {
        int _1st = 1, _2nd = 2, _nth = _1st;
        if (n == 1 || n == 2) { return n; }
        for (int i=3;i<=n;i++) {
            _nth = _1st + _2nd;
            _1st = _2nd;
            _2nd = _nth;
        }
        return _nth;
    }
};