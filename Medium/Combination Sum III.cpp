#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/combination-sum-iii/
// Difficulty : Medium

/* SIMPLE BACKTRACKING SOLUTION TO EXPLORE ALL COMBINATIONS */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int target;
    
    
    void solve (int i, int k, int sum) {
        
        if (k <= 0) {
            if (sum == target) { ans.push_back(temp); }
            return;
        }
        
        i++;
        while (i<10) {
            temp.push_back(i);
            solve(i,k-1,sum+i);
            temp.pop_back();
            i++;
        }
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        target = n;
        
        for (int i=1;i<10;i++) {
            temp.push_back(i);
            solve(i,k-1,i); 
            temp.pop_back();
        }
        
        return ans;
    }
};