#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-perfect-square/
// Difficulty : Easy

/* Time Complexity: O(sqrt(n)) - BRUTE FORCE */
class Solution {
public:
    bool isPerfectSquare(int num) {
         for (int i=1;i<46341 && i*i<=num;i++) { 
             if (i*i == num) { return true; } 
         }
         return false;
    }
};