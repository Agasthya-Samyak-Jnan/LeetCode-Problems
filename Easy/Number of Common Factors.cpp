#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-common-factors/
// Difficulty : Easy

/* Time Complexity: O(min(a,b)) */
class Solution {
public:
    int commonFactors(int a, int b) {
        int i=1, n = min(a,b),c=0;
        while (i<=n) {
            if (a%i == 0 && b%i == 0) { c++; }
            i++;
        }
        return c;
    }
};