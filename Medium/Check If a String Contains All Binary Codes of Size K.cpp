#include <bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Difficulty : Medium 

/* SLIDING WINDOW + HASH SET */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string> substrs;
        int i = -1, j = k-2, n = s.length();
        string temp = "";
        
        while (j < n-1) {
            i++;
            j++;
            temp = s.substr(i,k);
            substrs.insert(temp);
        }

        return (substrs.size() == pow(2,k));
    }
};