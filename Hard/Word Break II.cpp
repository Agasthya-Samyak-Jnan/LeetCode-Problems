#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/word-break-ii/
// Difficulty : Hard

/* BACKTRACKING TO FIND ALL POSSIBILITIES + TRIE TO EFFICIENTLY DETECT DICTIONARY WORDS */
/* FOR GOD'S SAKE DON'T USE DYNAMIC PROGRAMMING WHEN ITS POSSIBLE WITH BACKTRACKING AND WHEN BOTH METHODS YIELD SAME TIME COMPLEXITY */

class Trie {
public:
    Trie* a[26] = {0};
    bool is_Word = false;
        
    Trie() {}
    
    void insert(string word) {
        
         Trie* t = this;
         for (auto w : word) {
             t = t->a[w-'a'] ? t->a[w-'a'] : t->a[w-'a'] = new Trie();
         }
         t->is_Word = true; 
    }
    
};

class Solution {
public:
    string s;
    string temp;
    vector<string> ans;
    Trie* T;
    int n;
        
    void dfs (int i, Trie* t) {
        
        if (i == n) { 
            if (t->is_Word) { ans.push_back(temp); }
            return; 
        }
        
        if (t->is_Word) { 
            bool added = false;
            if (!temp.empty()) { added = true; temp += " "; } 
            dfs(i,T); 
            if (added) { temp.pop_back(); }
        }
        
        if (t->a[s[i]-'a']) { 
            temp += s[i];
            dfs(i+1,t->a[s[i]-'a']); 
            temp.pop_back();
        }    
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        T = new Trie();
        n = s.length();
        this->s = s;
        
        for (auto word : wordDict) { T->insert(word); }
        
        dfs(0,T);
        
        return ans;
        
    }
};