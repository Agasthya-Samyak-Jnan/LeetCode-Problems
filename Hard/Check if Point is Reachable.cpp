#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem :https://leetcode.com/problems/check-if-point-is-reachable/
// DIfficulty : Hard

/* Math Optimization: Time Complexity: O(logN + 1) */ 
// Fact : If GCD is a Power of 2 then the point is Reachable with suchh Operations given.
class Solution {
public:
    bool isReachable(int x, int y) {
         return (2147483648%__gcd(x,y) == 0);
    }
};

/* Brute Force */
class Solution {
public:
    bool isReachable(int x, int y) {
         while (x>1 && y>1) {
             while (x%2==0) { x/=2; } 
             while (y%2==0) { y/=2; }
             if (x==1 || y==1) { return true; }
             if (x<y) { y -= x; }
             else { x -= y; }
         }
        return (x==1 && y==1); 
    }
};