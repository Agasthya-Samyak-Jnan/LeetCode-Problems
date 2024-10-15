#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/replace-words/
// Difficulty : Medium 

// STANDARD TRIE BASED PROBLEM 
/* Custom Written Trie Data Structure */ 
class Trie {
public:
    Trie* a[26] = {0};
    bool is_Word;
        
    Trie() { is_Word = false; }
    
    void insert(string word) {
         Trie* t = this;
         for (auto w : word) {
             if (t->a[w-'a'] == nullptr) { t->a[w-'a'] = new Trie(); }
             t = t->a[w-'a'];
         }
         t->is_Word = true;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        
        string ans;
        int n = s.length();
        Trie* t = new Trie(), *T = t;
        
        for (auto word : dictionary) { t->insert(word); }
        for (int i=0;i<n;i++) {
            
            if (s[i] != ' ' && t->a[s[i]-'a']) { 

                t = t->a[s[i]-'a'];
                ans += s[i];

                if (t->is_Word) { 
                    t = T; 
                    while (i<n && s[i] != ' ') { i++; }
                    ans += " ";
                }       
            }
            
            else {
                while (i<n && s[i] != ' ') { ans += s[i]; i++; }
                ans += " ";
                t = T;
            }
        }
        
        if (ans.back() == ' ') { ans.pop_back(); }
        
        return ans;
    }
};