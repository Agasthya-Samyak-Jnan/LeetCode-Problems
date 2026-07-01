#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
// Difficulty : Easy

/* USING HASH TABLES FOR COUNTING/FREQUENCY */
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        int freq1[26] = {0}, freq2[26] = {0};

        for (auto c : word1) { freq1[c-'a']++; }
        for (auto c : word2) { freq2[c-'a']++; }

        for (int i=0;i<26;i++) { if (abs(freq1[i]-freq2[i]) > 3) { return false; } }

        return true;
    }
};

/* USING ONLY 1 HASH TABLE (SPACE OPTIMIZED) */
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        
        int freq[26] = {0};

        for (auto c : word1) { freq[c-'a']++; }
        for (auto c : word2) { freq[c-'a']--; }
        for (int i=0;i<26;i++) { if (abs(freq[i]) > 3) { return false; } }

        return true;
    }
};