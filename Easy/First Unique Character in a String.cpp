#include<bits/stdc++.h>

using namespace std;
// Link to the Problem : https://leetcode.com/problems/first-unique-character-in-a-string/
// Difficulty : Easy

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        for (int i=0; s[i]!=0; i++) { freq[s[i]-'a'] += 1; }
        for (int i=0; s[i]!=0; i++) { if (freq[s[i]-'a'] == 1) { return i; } }
        return -1;
    }
};