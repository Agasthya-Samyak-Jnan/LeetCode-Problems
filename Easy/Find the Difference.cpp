#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-the-difference/
// Difficulty : Easy

/* Time Complexity : O(N) = (2*N) , Space Complexity : O(1) = (26 Letters Frequency Array as Hash table) */
class Solution {
public:
    char findTheDifference(string s, string t) {
         int mp[26];
         memset(mp,0,sizeof(mp));
         for (int i=0;s[i]!=0;i++) { mp[s[i]-'a']++; }
         for (int i=0;t[i]!=0;i++) {
             if (mp[t[i]-'a']>0) { mp[t[i]-'a']--; }
             else { return t[i]; }
         }
        return '\0';
    }
};