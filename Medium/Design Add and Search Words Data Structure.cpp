#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Difficulty : Medium 

/* TRIE + DEPTH-FIRST SEARCH SOLUTION */
class WordDictionary {
private:
    WordDictionary* a[26] = {0};
    bool is_Word = false;
    
public:
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* t = this;
        for (auto c : word) { t = t->a[c-'a'] ? t->a[c-'a'] : t->a[c-'a'] = new WordDictionary(); }
        t->is_Word = true;
    }
    
    bool dfs (int i, WordDictionary* t, string& w, int n) {
        
        if (i >= n) { return t->is_Word; }
        
        if (w[i] != '.') { 
            if (t->a[w[i]-'a']) { return dfs(i+1,t->a[w[i]-'a'],w,n); } 
            else { return false; }
        }
        
        else {
            bool res = false;   
            for (auto letter : t->a) { if (letter) { res |= dfs(i+1,letter,w,n); } }
            return res;
        }    
    }
    
    bool search(string word) {
        return dfs(0,this,word,word.length());
    }
};