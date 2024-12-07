#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/search-suggestions-system/
// Difficulty : Medium 

/* TRIE + PRIORITY QUEUE (MIN HEAP) - SLOW BUT HIGHLY SCALABLE IMPLEMENTATION THAT CAN SUPPORT SUBSEQUENT QUERIES IN LESSER TIME. */
class Trie {
public:
    Trie* a[26] = {0};
    priority_queue<string,vector<string>,greater<string>> words;
        
    Trie() {}
    
    void insert(string word) {
         Trie* t = this;
         for (auto w : word) {
             t = (t->a[w-'a'] == nullptr) ? t->a[w-'a'] = new Trie() : t->a[w-'a'];
             t->words.push(word);
         }
    }  
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* t = new Trie();
        vector<vector<string>> ans;
        vector<string> temp = {};
        
        for (string& product : products) { t->insert(product); }
        
        for (char& c : searchWord) {
            if (t != nullptr) { t = t->a[c-'a']; }
            if (t != nullptr) {
                int count = 3;
                while (!t->words.empty() && count) { 
                    temp.push_back(t->words.top()); 
                    t->words.pop(); 
                    count--; 
                }
            }
            ans.push_back(temp);
            temp = {};
        }
        
        return ans;
    }
};