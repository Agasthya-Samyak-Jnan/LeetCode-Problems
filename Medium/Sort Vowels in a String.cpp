#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sort-vowels-in-a-string/
// Difficulty : Medium 

/* COLLECT VOWELS + SORTING + REPLACE VOWELS WITH SORTED VOWELS */
class Solution {
public:
    string sortVowels(string s) {
        
        string vowstr = "";
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};

        for (auto c : s) {
            if (vowels.find(c) != vowels.end()) { vowstr += c; }
        }

        sort(vowstr.begin(),vowstr.end());

        int j = 0;
        for (int i=0;s[i];i++) {
            if (vowels.find(s[i]) != vowels.end()) { s[i] = vowstr[j]; j++; }
        }

        return s;
    }
};
