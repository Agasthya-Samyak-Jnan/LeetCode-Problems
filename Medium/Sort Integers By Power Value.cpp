#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-integers-by-the-power-value/
// Difficulty : Medium 

/*
    NOTE :
    * Use Dynamic Programming to find Power , since during reduction of a number to 1, you will find numbers whose power was calculated already before.
    * For getting Kth Integer based on Power in Ascending Order, you can use - NORMAL SORTING , MIN HEAP OR QUICKSELECT. I have used QUICKSELECT here.
    * In this particular problem - Recomputations are less since rules given in question usually lead to more random numbers - hence pure recursion and memoization runtimes are similar.
*/

/* PURE RECURSION */
class Solution {
public:
    int power (int n) {
        if (n == 1) { return 0; } // Base Case
        if (n&1) { return 1 + power(3*n+1); } // Odd
        return 1 + power(n/2); // Even  
    }
    

    /* Quickselect Version */
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> powers;
        for (int i=lo;i<=hi;i++) { powers.push_back({power(i),i}); }
        nth_element(powers.begin(),powers.begin()+k-1,powers.end()); // Quickselect
        return powers[k-1].second;
    }

    /* Min Heap Version */ /*
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (int i=lo;i<=hi;i++) { pq.push({power(i),i}); }
        while (k!=1) { pq.pop(); k--; }
        return pq.top().second;
    }
    */

   /* Normal Sorting Version */ /*
   int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> powers;
        for (int i=lo;i<=hi;i++) { powers.push_back({power(i),i}); }
        sort(powers.begin(),powers.end());
        return powers[k-1].second;
    }
   */
};

/* PYTHON3 VERSION VERSION OF PURE RECURSION 

import heapq

class Solution:
    def power (self, n: int):
        if n == 1 : 
            return 0
        if n%2 == 1 :
            return 1 + self.power(3*n+1)
        return 1 + self.power(n/2)
    
    # Min Heap Version
    def getKth (self, lo: int, hi: int, k: int) -> int:
        
        pq = []
        
        for i in range(lo,hi+1) :
            heapq.heappush(pq,[self.power(i),i])
        
        for i in range(k,1,-1):
            heapq.heappop(pq) 
        
        return pq[0][1]

*/

/* RECURSION with MEMOIZATION */
class Solution {
public:
    int dp[260000] = {0};
    
    int power (int n) {
        if (n == 1) { return 0; } // Base Case
        if (dp[n] != 0) { return dp[n]; } // Previously Computed
        if (n&1) { return dp[n] = 1 + power(3*n+1); } // Odd
        return dp[n] = 1 + power(n/2); // Even  
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> powers;
        for (int i=lo;i<=hi;i++) { powers.push_back({power(i),i}); }
        nth_element(powers.begin(),powers.begin()+k-1,powers.end()); // Quickselect
        return powers[k-1].second;
    }
};

/* PYTHON3 VERSION OF RECURSION with MEMOIZATION

import heapq

class Solution:
    
    def __init__ (self):
        self.dp = [0]*260000
    
    def power (self, n: int):
        
        if n == 1 : 
            return 0
        
        if self.dp[n] != 0 :
            return self.dp[n]
        
        if n%2 == 1 :
            self.dp[n] = 1 + self.power(3*n+1)
            return self.dp[n]
        
        self.dp[n] = 1 + self.power(n//2)
        return self.dp[n]
    
    # Min Heap Version
    def getKth (self, lo: int, hi: int, k: int) -> int:
        
        pq = []
        
        for i in range(lo,hi+1) :
            heapq.heappush(pq,[self.power(i),i])
        
        for i in range(k,1,-1):
            heapq.heappop(pq) 
        
        return pq[0][1]
*/