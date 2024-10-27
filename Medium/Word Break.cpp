#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/word-break/
// Difficulty : Medium

/* DYNAMIC PROGRAMMING */

// NOTE : n = string length, m = number of words in 'wordDict', k = length of each word in 'wordDict'
// NOTE : substr(i,j) takes up O(c) Time for a string of length 'c' (Linear Time)

/* Memoisation - Recursive  Solution (Top-Down) */
// Ask the Question Recursively at every point : Can we complete a word at this (i) index of string?
/* Time : O(n*m*k) */
class Solution {
public:
    vector<int> memo;
    vector<string> wordDict;
    string s;
    
    bool dp (int i) {
        
        // You can always build empty strings. (i >= -1 and i == -1 only when i == word.length()-1 implying this word can be built. (0-indexing))
        if (i<0) { return true; }
        
        // If we have already found if word can be built or not till this 'i' index.
        if (memo[i] != -1) { return memo[i]; }
        
        // Check if any word can be built + previosuly words have been till this index 'i'.
        for (auto word : wordDict) {
            int w = word.size();
            if (i-w+1 < 0) { continue; }
            if (s.substr(i-w+1,w) == word && dp(i-w)) {
                // memoise this result and then return.
                memo[i] = 1;
                return true;
            }
        }
        
        // memoise this result and then return.
        memo[i] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        this->wordDict = wordDict;
        this->s = s;
        memo = vector<int>(n,-1);
        
        return dp(n-1);
    }
};

/* Tabulation - Iterative Solution (Bottom-Up) */
// Build the Words from Start to End
/* Time : O(n*m*k) */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        vector<int> dp(n,0);
        
        for (int i=0;i<n;i++) {
            for (auto word : wordDict) {
                int w = word.size();
                if (i < w-1) { continue; }
                // (i == w-1) needed when you are checking the first word, (i<0 for first word since i <= first word length)
                // Check if Words were built till [i-w] , using dp[i-w].
                // If they were built till this word i.e till [i-w], then check if we built an existing word now.
                if ((i == w-1 || dp[i-w]) && (s.substr(i-w+1,w) == word)) { dp[i] = 1; break; }
            }
        }
        
        return dp[n-1];
    }
};


/* Tabulation - Iterative Solution (Bottom-Up) - OPTIMIZED STRING MATCHING USING TRIE */
// Build the Words from Start to End
/* Time : O(m*k + n*n)*/
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
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        Trie* T = new Trie(), *t;
        vector<int> dp(n,0);
        
        for (auto word : wordDict) { T->insert(word); }
        
        for (int i=0;i<n;i++) {
            t = T;
            if (i == 0 || dp[i-1]) {
                for (int j=i;j<n;j++) {
                    if (!t->a[s[j]-'a']) { break; }
                    t = t->a[s[j]-'a'];
                    if (t->is_Word) { dp[j] = 1; }
                }
            }
        }
        
        return dp[n-1];
    }
};