#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/button-with-longest-push-time/description/
// Difficulty : Easy

/* NORMAL ARRAY PROBLEMS */
class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& e) {

        int n = e.size(), longestTimeButton = e[0][0], longestTime = e[0][1];  

        for (int i=1;i<n;i++) {
            int timeTaken = e[i][1] - e[i-1][1];
            if (timeTaken > longestTime) {
                longestTime = timeTaken;
                longestTimeButton = e[i][0];
            }
            else if (timeTaken == longestTime) {
                longestTimeButton = min(longestTimeButton,e[i][0]);
            }
        } 
        
        return longestTimeButton;
    }
};