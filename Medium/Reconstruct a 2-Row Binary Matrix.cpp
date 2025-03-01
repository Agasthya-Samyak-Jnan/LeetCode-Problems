#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
// Difficulty : Medium 

/* GREEDY */
class Solution {
    public:
        vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
            
            int n = colsum.size();
            vector<vector<int>> ans(2,vector<int>(n));
    
            for (int i=0;i<n;i++) {
    
                if (colsum[i] == 0) {
                    ans[0][i] = ans[1][i] = 0;
                }
    
                if (colsum[i] == 2) {
                    if (upper > 0 and lower > 0) { 
                        ans[0][i] = ans[1][i] = 1; 
                        upper--; lower--;
                    }
                    else { return {}; }
                }
                
                if (colsum[i] == 1) {
                    if (upper >= lower) {
                        if (upper > 0) { ans[0][i] = 1; upper--; }
                        else { return {}; }
                    }
                    else {
                        if (lower > 0) { ans[1][i] = 1; lower--; }
                        else { return {}; }
                    }
                }
    
            }
    
            if (upper == 0 and lower == 0) { return ans; }
            
            return {};
        }
};