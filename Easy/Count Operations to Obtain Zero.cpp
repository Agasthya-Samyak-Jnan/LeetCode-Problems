#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-operations-to-obtain-zero/
// Difficulty : Easy 

/* SIMULATION */
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        while (num1 and num2) {
            if (num1 >= num2) { num1 -= num2; }
            else { num2 -= num1; }
            ops++;
        }
        return ops;
    }
};

/* OPTIMIZATION USING COMMON SENSE (WHICH I WAS LAZY TO THINK ABOUT LOL!) */
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        while (num1 and num2) {
            if (num1 >= num2) { ops += (num1/num2); num1 %= num2; }
            else { ops += (num2/num1); num2 %= num1; }
        }
        return ops;
    }
};