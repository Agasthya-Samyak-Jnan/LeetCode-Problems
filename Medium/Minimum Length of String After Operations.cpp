#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-length-of-string-after-operations/
// Difficulty : Medium

/* INTUITION + HASH TABLE */
class Solution {
public:
    int minimumLength(string s) {

        int mp[26] = {0};
        int len = 0;

        for (int i=0;s[i];i++) {
            mp[s[i]-'a']++; len++;
            if (mp[s[i]-'a'] == 3) { len -= 2; mp[s[i]-'a'] = 1; }
        }

        return len;
    }
};