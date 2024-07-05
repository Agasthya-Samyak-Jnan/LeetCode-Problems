#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/min-cost-climbing-stairs/
// Difficulty : Easy

/* 
   DYNAMIC PROGRAMMING - STEPS OF OPTIMIZATION : Go from 1 to 4 in Order,
   (*) => FIRST TRY THINKING OF RECURRENCE RELATION.
   1. Recurrence Relation TO First Solution - Recursive Solution ( Exponential Time | Recursion Stack Space )
   2. OPTIMIZE - Recursive to  Memoized-Recursive ( Exponential to Linear Time | Recursion Stack Space + Memoization Array Space )
   3. OPTIMIZE - Memoized-Recursive to Memoized-Iterative ( Linear Time | Space Optimized - Removed Recursion Stack Space )
   4. OPTIMIZE - Memoized-Iterative to Iterative ( Linear Time | O(1) Constant Space )
*/

/* Recursive Solution - First Approach : TC = O(2^N)(Approx.), SC = O(2^N) - Time Limit Exceeded */
class Solution {
public: 
    int minCost (vector<int> &cost,int i) {
        if (i<0) { return 0; }
        if (i==0 || i==1) { return cost[i]; }
        return  cost[i] + min(minCost(cost,i-1),minCost(cost,i-2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCost(cost,cost.size()-1),minCost(cost,cost.size()-2));
    }
};

/* 2. From Recursive to Memoized-Recursive Solution */
class Solution {
public:
    vector<int> dp;
    
    int minCost (vector<int> &cost,int i) {
        if (i<0) { return 0; }
        if (i==0 || i==1) { return cost[i]; }
        if (dp[i] == 0) { dp[i] = cost[i] + min(minCost(cost,i-1),minCost(cost,i-2)); }
        return  dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i=0;i<n;i++) { dp.push_back(0); }
        return min(minCost(cost,n-1),minCost(cost,n-2));
    }
};

/* 3. From Memoized-Recursive to Memoized-Iterative Solution : TC = O(N), SC = O(N) = N (Array) */
class Solution {
public:
    vector<int> dp;
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        for (int i=0;i<n;i++) {
            if (i<2) { dp.push_back(cost[i]); }
            else { dp.push_back(cost[i] + min(dp[i-1],dp[i-2])); }
        }
            
        return min(dp[n-2],dp[n-1]);
    }
};

/* 4. Ultimate Solution : From Memoized-Iterative to Constant-Space-Iterative Solution : TC = O(N), SC = O(1) */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int prev1 = cost[1], prev2 = cost[0];
        int mincost;
        
        for (int i=2;i<n;i++) {
            mincost = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = mincost;
        }
            
        return min(prev1,prev2);
    }
};