#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/group-anagrams/
// Difficulty : Medium 

/*
    Anagram = a permutation of a string.
    When you sort any anagram of a string they all convert to a same anagram - sorted version of that string.
    When a string is sorted and it matches a previously sorted anagram then its a anagram of that string.
    USE SORTED ANAGRAM AS THE KEY FOR THAT GROUP OF ANAGRAMS OF A PARTICULAR STRING.
*/
class Solution {
public:
    int freq[26] = {0};
    
    void count_sort_strings (string &s) {
        int maxi = INT_MIN, mini = INT_MAX;
        for (auto c : s) { 
            freq[c-'a']++; 
            maxi = max(maxi,c-'a'); 
            mini = min(mini,c-'a');  
        }
        for (int i=mini,j=0;i<=maxi;i++) {
            while (freq[i]) { s[j++] = ('a'+i); freq[i]--; }
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Sorted Anagram as key in this Hash Map.
        unordered_map<string,int> mp;
        vector<vector<string>> ans;
        int i = 1;
        
        ans.push_back({});
        
        for (auto s : strs) {
            string key = s;
            count_sort_strings(key);
            if (!mp[key]) { mp[key] = i; i++; ans.push_back({}); }
            ans[mp[key]].push_back(s);
        }
        
        ans.erase(ans.begin());

        return ans;
    }
};