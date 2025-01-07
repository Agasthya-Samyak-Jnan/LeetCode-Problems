#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
// Difficulty : Medium 

/* BASIC INTUITION */
class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.length();
        vector<int> ans(n,0);

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (boxes[j] == '0' || i == j) { continue; }
                ans[i] += abs(j-i);
            }
        }

        return ans;
    }
};