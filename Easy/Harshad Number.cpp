#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/harshad-number/
// Difficulty: Easy

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, org = x;
        while (x > 0) {
            sum += x%10;
            x /= 10;
        } 
        if (org%sum == 0) { return sum; }
        return -1;
    }
};