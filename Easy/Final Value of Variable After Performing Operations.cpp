#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Difficulty : Easy  

/* SIMULATION */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int val = 0;
        for (auto op : operations) { val += (op[1] == '+' ? 1 : -1); }

        return val;
    }
};