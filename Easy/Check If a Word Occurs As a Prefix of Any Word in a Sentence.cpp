#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Difficulty : Easy

/* USING TRIE DATA STRUCTURE */
class Trie {
public:
    Trie* a[26] = {0};
    int is_Word = 0;
        
    Trie() {}
    
    void insert(string word) {
         Trie* t = this;
         for (auto w : word) {
             t = (t->a[w-'a'] == nullptr) ? t->a[w-'a'] = new Trie() : t->a[w-'a'];
         }
        
         t->is_Word = true;
    }
};

class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        
        Trie* T = new Trie(),*t;
        int n = s.length(),k = 1;
        
        T->insert(searchWord);
        t = T;
        
        for (int i=0;i<n;i++) {
            if (isalpha(s[i]) && t->a[s[i]-'a']) { 
                t = t->a[s[i]-'a']; 
                if (t->is_Word) { return k; }
            }
            else {
                t = T;
                while (s[i] != ' ' && i<n) { i++; }
            }
            if (s[i] == ' ') { k++; }
        }
        
        return -1;
    }
};

/* USING TWO POINTERS */
class Solution {
public:
    int isPrefixOfWord(string s1, string s2) {
        
        int i = 0, j = 0, k = 1, m = s2.length(), n = s1.length();
        
        while (i<n) {
            if (s1[i] == s2[j]) { 
                i++; j++; 
                if (j == m) { return k; }
            }
            else {
                while (s1[i] != ' ' && i<n) { i++; }
                k++; i++;
                j = 0;
            }
        }
        
        return -1; 
    }
};