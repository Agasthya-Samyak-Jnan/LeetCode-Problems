#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/stream-of-characters/
// Difficulty : Hard

/* DATA STREAM KIND OF MEMORY AND TIME MANAGEMENT WITH TRIE USAGE */
class Trie {
private:
    Trie* a[26] = {0};
    bool is_Word = false;
    
public:    
    Trie () {}
     
    void insert (string& w, int n) {
        Trie* t = this;
        for (int i=n-1;i>=0;i--) { t = t->a[w[i]-'a'] ? t->a[w[i]-'a'] : t->a[w[i]-'a'] = new Trie(); }
        t->is_Word = true;
    }
    
    bool has_Suffix (string& w,int n) {
        Trie* t = this;
        for (int i=n-1;i>=0;i--) {
            if (t->a[w[i]-'a']) {
                t = t->a[w[i]-'a'];
                if (t->is_Word) { return true; }
            }
            else { return false; }
        }
        return false;
    }
    
};

class StreamChecker {
public:
    Trie* T;  // Trie for Words
    string str; // Character Stream
    int max_len = 0, n = 0; // Stream Properties
    
    // Build Trie with Words
    StreamChecker(vector<string>& words) {
        T = new Trie();
        for (auto word : words) {
            max_len = word.length() > max_len ? word.length() : max_len;
            T->insert(word,word.length());
        }
    }
    
    bool query(char letter) {
        
        // Update the Stream and Search Suffix (i.e Prefix in Reversed Stream)
        str += letter; n++;
        // Keep only Characters equal to Maximum Word Length to be checked. (Otherwise YOU WILL EXCEED MEMORY LIMITS)
        // You don't really need other characters.
        if (str.length() > max_len) { str.erase(str.begin()); n--; }
        return T->has_Suffix(str,n);       
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */