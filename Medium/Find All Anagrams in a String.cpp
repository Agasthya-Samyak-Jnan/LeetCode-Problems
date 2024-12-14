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

/* PYTHON3 VERSION 

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        if len(p) > len(s) :
            return []
        
        ans = []
        freq1 = defaultdict(int)
        freq2 = defaultdict(int)
        i = 0
        j = len(p)-1
        n = len(s)
        
        for k in range(len(p)) :
            freq1[p[k]] += 1
            freq2[s[k]] += 1
        
        while j < n :
            
            if freq1 == freq2 :
                ans.append(i)
                
            freq2[s[i]] -= 1
            if freq2[s[i]] == 0 :
                del freq2[s[i]]
            i += 1
            j += 1
            if j < n :
                freq2[s[j]] += 1
        
        
        return ans
*/