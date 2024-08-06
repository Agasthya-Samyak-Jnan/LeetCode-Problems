#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Difficulty : Easy

class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.length();
        
        int mintaps = 0, keytaps = 0;
        
        for (int i=0;i<n;i++) {
            mintaps += ((keytaps++)/8)+1;
        }
        
        return mintaps;
    }
};