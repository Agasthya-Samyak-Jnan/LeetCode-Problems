#include <bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
// Difficulty: Medium

using namespace std;

/* TRIE-BASED SOLUTION WITH DEPTH-FIRST SEARCH in TRIE */
class Trie {
public:
    unordered_map<string,Trie*> a;
    bool is_path = false;
        
    Trie () {}
    
    void insert(string word) {
        
        Trie* t = this;
        string temp = "";
        int i = 1;

        while (word[i]) {
            if (word[i] == '/') {
                t = t->a[temp] ? t->a[temp] : t->a[temp] = new Trie();
                temp = "";
            }
            else { temp += word[i]; }
            i++;
        }
        t = t->a[temp] ? t->a[temp] : t->a[temp] = new Trie();
        t->is_path = true;
    }

    bool hasPrefix (string word) {

        Trie* t = this;
        string temp = "";
        int i = 1;

        while (word[i]) {
            if (t->is_path) { return true; }
            if (word[i] == '/') { 
                t = t->a[temp]; 
                temp = "";
            }
            else { temp += word[i]; }
            i++;
        }

        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        Trie* t = new Trie();
        vector<string> ans;

        for (auto f : folder) { t->insert(f); }
        for (auto f : folder) { if (!t->hasPrefix(f)) { ans.push_back(f); } }

        return ans;
    }
};