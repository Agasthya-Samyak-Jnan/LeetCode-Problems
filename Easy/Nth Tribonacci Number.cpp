#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/n-th-tribonacci-number/
// Difficulty : Easy

class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1, temp = 0;
        if (n == 0) { return 0; }
        while (n-2 > 0) {
           temp = first+second+third;
           first = second;
           second = third;
           third = temp;
           n--;
        }
        return third;
    }
};