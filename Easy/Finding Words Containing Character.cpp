#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-words-containing-character/
// Difficulty : Easy

/* Time Complexity : O(N^2) - Brute Force - String Matching Algorithm Pattern */
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> ans;
        int n = words.size();
        
        for (int i=0;i<n;i++) {
            int m = words[i].length();
            for (int j=0;j<m;j++) {
                if ( words[i][j] == x) { ans.push_back(i); break; }
            }
        }
        return ans;
    }
};