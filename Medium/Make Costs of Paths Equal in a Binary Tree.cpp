#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/
// Difficulty : Medium

/* BINARY TREE + DEPTH-FIRST SEARCH : HOW TO USE RECURSION TO GET WHAT YOU WANT. */
class Solution {
public:

    vector<int> cost;
    int n, increments = 0;

    int solve (int i) {
        if (i >= n) { return 0; }
        int left = solve(2*i+1);
        int right = solve(2*i+2);
        increments += abs(left-right);
        return cost[i] + max(left,right);
    }


    int minIncrements(int n, vector<int>& cost) {
        this->n = n;
        this->cost = cost;
        solve(0);
        return increments;
    }
};