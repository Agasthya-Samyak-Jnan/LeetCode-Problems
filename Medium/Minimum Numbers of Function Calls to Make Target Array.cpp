#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/
// Difficulty : Medium

/* Direct - Intuitive Solution */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int minOps = 0, minimum = INT_MAX;
        int n = nums.size();
        vector<int> isZero(n,0);
        int zeroes = 0;
        int temp = 0;
        
        while (zeroes != n) {
            
            for (int i=0;i<n;i++) { 
                temp = nums[i]&1;
                nums[i] -= temp; 
                minOps += temp;
                if (nums[i] == 0 && !isZero[i]) { isZero[i]= 1; zeroes++; }
            }
            
            for (int i=0;i<n;i++) { nums[i] = nums[i]/2; }
            minOps++;
        }
   
        return minOps-1;
    }
};
/* Optimised Solution - Math */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int increments = 0, doubles = 0, minimum = INT_MAX;
        int n = nums.size();
        
        for (int i=0;i<n;i++) {
            for (int k = nums[i]; k > 0; k /= 2) {
                increments += k&1;
            }
            if (nums[i]) { doubles = max(doubles,(int)log2(nums[i])); }
        }
         
        return increments + doubles;
    }
};