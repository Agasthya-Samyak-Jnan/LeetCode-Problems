#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/bitwise-and-of-numbers-range/
// Difficulty : Medium

/* Time Complexity: O(log2(N)) */

/* Helped Hint: Find the Common Prefix (Common bits from Left Side of Binary Representation) */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int n=0;
       while (left != right) {
           left >>= 1;
           right >>= 1;
           n++;
       }
       return left<<n;
    }
};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & right-1;
        }
        return right;
    }
};