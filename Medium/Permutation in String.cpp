#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/permutation-in-string/
// Difficulty : Medium

/* 
    Anagram of String == Permutation of String == String formed by rearranging Letters of a String. - Triggers String Handling Idea.
    Observations :
    1. Number of Letters in each Anagram is same as Original String - String Length Remains SAME. - Triggers Sliding Window Idea.
    2. Number of Repetitions of each Unique Letter in String (Letter's Frequency) is SAME in all Permutations. - Triggers Hash Table Idea

    Using Above we can design a Solution.
*/

/* SLIDING WINDOW + HASH TABLE */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m = s1.length(), n = s2.length();
        if (n < m) { return false; }
        
        vector<int> rmp(26,0), mp(26,0);
        for (int i=0;i<m;i++) { mp[s1[i]-'a']++; rmp[s2[i]-'a']++; }
        
        for (int i=0;i<=n-m;i++) {
            if (rmp == mp) { return true; }
            rmp[s2[i]-'a']--;
            if (s2[i+m]) { rmp[s2[i+m]-'a']++; }
        }
        
        return false;
    }
};