#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/custom-sort-string
// Difficulty : Medium

/* COUNTING SORT */
class Solution {
public:
    string customSortString(string order, string s) {
        
        int letter[26] = {0};
        
        for (auto& c : s) { letter[c-'a']++; }
        
        s = "";
        
        for (auto& c : order) {
            while (letter[c-'a']) {
                s += c;
                letter[c-'a']--;
            }
        }
        
        for (int i=0;i<26;i++) {
            while (letter[i]) {
                s += ('a'+i);
                letter[i]--;
            }
        }
        
        return s;
    }
};



