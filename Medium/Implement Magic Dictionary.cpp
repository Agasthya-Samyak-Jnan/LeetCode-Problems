#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/implement-magic-dictionary/
// Difficulty : Medium 

/* Intuition - BASED SOLUTION */
class MagicDictionary {
private:
    vector<string> words;
    
public:
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string word) {
        
        int m = word.length();
        
        for (auto w : words) {
            int n = w.length(),diff = 0;
            if (n != m) { continue; }
            for (int i=0;i<n;i++) {
                diff += (w[i] != word[i]);
            }
            if (diff == 1) { return true; }
        }
        return false;
    }
};

/* TRIE - BASED SOLUTION */
class MagicDictionary {
public:
    MagicDictionary* a[26] = {0};
    bool is_Word;
    
    MagicDictionary() { is_Word = false; }
    
    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            MagicDictionary* m = this;
            for (char c : word) {
                m = m->a[c-'a'] ? m->a[c-'a'] : m->a[c-'a'] = new MagicDictionary();
            }
            m->is_Word = true;
        }
    }
    
    bool dfs (int i, string& w, MagicDictionary* m, int n, int s) {
        
        if (i>=n) { return m->is_Word && s == 1; }
        
        bool res = false; 
        
        if (m->a[w[i]-'a']) { res |= dfs(i+1,w,m->a[w[i]-'a'],n,s); }
        
        if (s == 0) {
            for (int j=0;j<26;j++) {
                if (j != w[i]-'a' && m->a[j]) { res |= dfs(i+1,w,m->a[j],n,s+1); }
            }
        }
        
        return res;
    }
    
    bool search(string word) {
        return dfs(0,word,this,word.length(),0);
    }
};
