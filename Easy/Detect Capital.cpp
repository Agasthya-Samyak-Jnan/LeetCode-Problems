#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/detect-capital/
// Difficulty : Easy

class Solution {
public:
    bool detectCapitalUse(string word) {
         int caps = 0;
         for (int i=0;word[i]!=0;i++) {
             if (word[i] < 97) { caps++; }
         }
         return (caps == 0 || caps == word.length()) || (caps == 1 && word[0] < 97);
    }   
};