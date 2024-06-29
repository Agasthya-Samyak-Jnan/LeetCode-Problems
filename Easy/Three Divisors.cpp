#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/three-divisors/
// Difficulty : Easy

/* Time Complexity : O(N/2) */
class Solution {
public:
    bool isThree(int n) {
         int k=2;
         for (int i=2;i<=n/2;i++) {
             if (n%i == 0) { 
                 if (k == 3) { return false; }
                 else { k++; }
             }
         }
        return k==3;
    }
};