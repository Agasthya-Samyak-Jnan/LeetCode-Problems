#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/most-common-word/
// Difficulty : Easy

/* HASH TABLE SOLUTION */
class Solution {
    public:
        string mostCommonWord(string p, vector<string>& banned) {
            
            unordered_map<string,int> Banned,mp;
            int n = p.length();
            string word, mostCommon = "";
            
            for (string& word : banned) { Banned[word] = 1; }
            
            for (int i=0;i<n;i++) {
                word = "";
                while (i<n and !isalpha(p[i])) { i++; }
                while (i<n and isalpha(p[i])) { 
                    word += (p[i] >= 'A' and p[i] <= 'Z') ? p[i] + 32 : p[i]; 
                    i++; 
                }
                mp[word]++;
                // cout<<word<<" - "<<mp[word]<<"\n";
                if (!Banned[word]) { mostCommon = mp[mostCommon] < mp[word] ? word : mostCommon; }
            }
            
            return mostCommon;
        }
    };