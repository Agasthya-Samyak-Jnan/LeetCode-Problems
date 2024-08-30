#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Difficulty : Medium

/* 
    This is Inefficient When Length of Strings are more than 26. Think Why? Cannot we just compare whole HASH TABLES beyond 26 Length? 
    See Second Solution Below.
*/

/* Time Complexity : [ (m-n)*n ] - This can go BONKERS when (n > 26), compared to second solution below. */
vector<int> findAnagrams(string s, string p) {
        
        int m = s.length(), n = p.length();
        
        if (m < n) { return {}; }
        
        int rmp[26] = {0};
        int mp[26]  ={0};
        vector<int> ans;
        
        for (int i=0;i<n;i++) { mp[p[i]-'a']++; rmp[s[i]-'a']++; }
        
        for (int i=0;i<=m-n;i++) {
            bool anagram = true;
            for (int j=0;j<n;j++) {
                if (rmp[p[j]-'a'] != mp[p[j]-'a']) { anagram = false; break; }
            }
            rmp[s[i]-'a']--;
            if (s[i+n]) { rmp[s[i+n]-'a']++; }
            if (anagram) { ans.push_back(i); }
        }
        
        return ans;
    }

/* Time Complexity : [ (m-n)*26 ] */
vector<int> findAnagrams(string s, string p) {
        
        int m = s.length(), n = p.length();
        
        if (m < n) { return {}; }
        
        vector<int> rmp(26,0), mp(26,0);
        vector<int> ans;
        
        for (int i=0;i<n;i++) { mp[p[i]-'a']++; rmp[s[i]-'a']++; }
        
        for (int i=0;i<=m-n;i++) {
            if (rmp == mp) { ans.push_back(i); }
            rmp[s[i]-'a']--;
            if (s[i+n]) { rmp[s[i+n]-'a']++; }
        }
        
        return ans;
    }

