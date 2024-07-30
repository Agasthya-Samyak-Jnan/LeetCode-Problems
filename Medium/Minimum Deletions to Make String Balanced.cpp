#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Difficulty : Medium

/* With Stack - TC : O(n) , SC : O(n) */
class Solution {
public:
    int minimumDeletions(string str) {
        stack<char> s;
        int n = str.length();
        int minDels = 0;
        
        for (int i=0;i<n;i++) {
            if (str[i] == 'b') { s.push('b'); }
            else if (!s.empty()) { s.pop(); minDels++; }
        }
        
        return minDels;
    }
};

/* Without Stack - TC : O(n) , SC : O(1) */
class Solution {
public:
    int minimumDeletions(string str) {
        int n = str.length();
        int minDels = 0, b_count = 0;
        
        for (int i=0;i<n;i++) {
            if (str[i] == 'b') { b_count++; }
            else if (b_count) { b_count--; minDels++; }
        }
        
        return minDels;
    }
};