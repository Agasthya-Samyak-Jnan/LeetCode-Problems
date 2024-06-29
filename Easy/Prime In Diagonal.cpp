#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/prime-in-diagonal/
// Difficulty : Easy

/* Time Complexity : O( N*(2*sqrt(N)) )*/
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int max_prime = 0, n = nums.size();
        for (int i=0;i<n;i++) {
            if (is_prime(nums[i][i])) { max_prime = max(max_prime,nums[i][i]); }
            if (is_prime(nums[i][n-1-i])) { max_prime = max(max_prime,nums[i][n-i-1]); }
        }
        return max_prime;
    }
    bool is_prime (int num) {
        if (num <= 1) { return false; }
        for (int i=2;i*i<=num;i++) {
            if (num%i == 0) { return false; }
        }
        return true;
    }
};