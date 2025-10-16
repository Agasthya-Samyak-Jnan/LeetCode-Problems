#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-segments-in-a-string/
// Difficulty : Easy  

/* SIMULATION - TAKE CARE OF ALL TRICKY INPUTS POSSIBLE :D */
class Solution {
public:
    int countSegments(string s) {
        char prev = ' ';
        int segments = 0;
        for (auto c : s) { segments += (prev == ' ' and c != ' '); prev = c;  }
        return segments;
    }
};