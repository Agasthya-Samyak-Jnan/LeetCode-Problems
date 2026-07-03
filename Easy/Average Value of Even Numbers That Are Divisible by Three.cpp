#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
// Difficulty : Easy

/* 
   SIMPLE MATH : A number that's even (divisible by 2) and divisble by 3 is always divisible by 6. 
   (LCM of all given divisors divides numbers that are divisible by all given divisors) 
*/
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n = 0, sum = 0;
        for (auto num : nums) {
            if (num % 6 == 0) { sum += num; n++; }
        }
        return (n==0) ? 0 : sum/n;
    }
};