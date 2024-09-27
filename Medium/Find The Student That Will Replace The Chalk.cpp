#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// Difficulty : Medium

/* RUNNING PREFIX SUM TO AVOID INTEGER OVERFLOW ERROR , PREFIX SUM ARRAY WILL ALSO WORK. */
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size(),i=0;
        int sum = 0;
        
        for (int i=0;i<n;i++) { 
            sum += chalk[i];
            if (sum > k) { return i; } 
        }
        
        k %= sum; sum = chalk[i];
        
        while (sum <= k) { sum += chalk[++i]; }
        
        return i;
        
    }
};