#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
// Difficulty : Medium

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

/* UNBOUNDED SEARCH - BRUTE FORCE */
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& c, int z) {
        
        vector<vector<int>> ans;
        
        for (int x=1;x<=1000;x++) {
            for (int y=1;y<=1000;y++) {
                if (c.f(x,y) == z) { ans.push_back({x,y}); }
            }
        }
        
        return ans;
    }
};

/* BOUNDED SEARCH - TWO POINTERS */
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& c, int z) {
        
        vector<vector<int>> ans;
        int upper_limit = 1001;
        
        for (int x=1;x<=1000;x++) {
            if (c.f(x,1) > z) { break; }
            for (int y=1;y<upper_limit;y++) {
                int temp = c.f(x,y);
                if (temp == z) { ans.push_back({x,y}); }
                else if (temp > z) { upper_limit = y; }
            }
        }
        
        return ans;
    }
};