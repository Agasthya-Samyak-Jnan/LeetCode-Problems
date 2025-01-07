#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/frog-jump/
// Difficulty : Hard

/* DYNAMIC PROGRAMMING SOLUTION */

/* PURE RECURSION */
class Solution {
public:
    unordered_set<int> s;
    int goal = 0;

    bool solve (int pos, int prev_jump) {

        if (s.find(pos) == s.end()) { return false; }
        if (pos == goal) { return true; }

        bool canJump = (prev_jump-1 > 0 && solve(pos+prev_jump-1,prev_jump-1));
        canJump = canJump || solve(pos+prev_jump,prev_jump) || solve(pos+prev_jump+1,prev_jump+1);
        
        return canJump;
    }

    bool canCross(vector<int>& stones) {
        
        s = unordered_set<int>(stones.begin(),stones.end());
        goal = stones.back();
        if (s.find(1) == s.end()) { return false; }
        return solve(1,1);

    }
};

/* MEMOIZED RECURSION (TOP-DOWN) */
class Solution {
public:
    // 2D Memoization Table = dp , Stone Positions Set = s.
    unordered_map<int,unordered_map<int,int>> dp;
    unordered_set<int> s;
    int goal = 0;

    bool solve (int pos, int prev_jump) {
        // If there is no stone where frog wanted to jump, its not possible to reach goal from there. Go Back.
        if (s.find(pos) == s.end()) { return false; }
        // If current stone is our destination , its reachable. Success.
        if (pos == goal) { return true; }
        // If we had previously checked what happened going through this stone , then return that previous result itself.
        if (dp[pos].find(prev_jump) != dp[pos].end()) { return dp[pos][prev_jump]; }

        // Calculate if its possible to reach goal stone by doing prev_jump-1, prev_jump and prev_jump+1 steps from this stone.
        // Memoize the result at the same time for future computations.
        dp[pos][prev_jump] = (prev_jump-1 > 0 && solve(pos+prev_jump-1,prev_jump-1));
        dp[pos][prev_jump] = dp[pos][prev_jump] || solve(pos+prev_jump,prev_jump) || solve(pos+prev_jump+1,prev_jump+1);
        
        // Tell if its possible or not.
        return dp[pos][prev_jump];
    }

    bool canCross(vector<int>& stones) {
        
        // Memorize Positions of Stones to compute Jumps only from those positions.
        s = unordered_set<int>(stones.begin(),stones.end());
        goal = stones.back(); // Last Stone is our Destination.
        // Since first Jump is always 1 Step, if there is no Stone on position 1 , its impossible.
        if (s.find(1) == s.end()) { return false; }
        // Find if its possible to cross the river.
        return solve(1,1);
        
    }
};

/* TABULATION SOLUTION */
class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        unordered_set<int> s(stones.begin(),stones.end());
        long goal = stones.back();
        unordered_map<long,unordered_map<long,int>> dp;
        vector<int> drn = {-1,0,+1};

        if (s.find(1) == s.end()) { return false; }

        dp[1][1] = 1;

        for (auto stone : stones) {
            if (dp[stone].empty()) { continue; }
            for (auto j : dp[stone]) {
                for (auto dx : drn) {
                    if (j.first+dx > 0 && s.find(stone+j.first+dx) != s.end()) { 
                        dp[stone+j.first+dx][j.first+dx] = 1; 
                    }
                }
            }
        }

        return !dp[goal].empty();
    }
};