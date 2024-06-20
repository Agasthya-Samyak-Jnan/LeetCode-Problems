#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/valid-word/
// Difficulty : Easy

class Solution {
public:
    bool isValid(string word) {
         if (word.length()<3) { return false; }
         bool vowel = false, consonant = false;
         int n = word.length();
         vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
         for (int i=0;i<n;i++) {
             if (!isalnum(word[i])) { return false; }
             if (!isdigit(word[i])) {
             if (find(vowels.begin(),vowels.end(),word[i]) != vowels.end()) { vowel = true; }
             else { consonant = true; }
             }
         }
         return (consonant&&vowel);
    }
};