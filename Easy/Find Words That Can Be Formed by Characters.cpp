#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Difficulty : Easy

/* STRINGS + HASH TABLES */
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int c[26] = {0}, w[26] = {0}, sum = 0;

        for (auto letter : chars) { c[letter-'a']++; }
        
        for (auto word : words) {
            for (auto letter : word) { w[letter-'a']++; }
            bool buildable = true;
            for (int i=0;i<26;i++) {
                if (w[i] > c[i]) { buildable = false; break; }
            }
            if (buildable) { sum += word.length(); }
            memset(w,0,26*sizeof(int));
        }

        return sum;
    }
};