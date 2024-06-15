#include<bits/stdc++.h>

// Link to the Problem: https://leetcode.com/problems/implement-trie-prefix-tree/
// Difficulty: Medium

using namespace std; 

/* Designing Problem - TRIE Data Structure (Prefix Tree) */

/* Applications of TRIE Data Structure: 
 * 1. Word Suggestion Feature when you type words in keyboards is implemented using Trie.
 * 2. Autocompletion of Words in keyboards uses Trie.
 * 3. Spelling Mistakes Highlighting in Keyboards is done using Trie.
*/

class Trie {
public:
    Trie* a[26];
    bool is_Word;
        
    Trie() {
       for (int i=0;i<26;i++) { a[i] = NULL; }
       is_Word = false;
    }
    
    void insert(string word) {
         int n = word.length();
         Trie* t = this,*newnode;
         for (int i=0;i<n;i++) {
             if (t->a[word[i]-'a'] == NULL) {
                 newnode = new Trie();
                 t->a[word[i]-'a'] = newnode;
             }
             t = t->a[word[i]-'a'];
         }
         t->is_Word = true;
    }
    
    bool search(string word) {
         int i=0, n = word.length();
         Trie* t = this;
         for (i=0;i<n;i++) {
             if (t->a[word[i]-'a'] != NULL) {
                 t = t->a[word[i]-'a'];
             }
             else { return false; }
         }
         if (i == n && t->is_Word) { return true; }
         else { return false; }
    }
    
    bool startsWith(string prefix) {
         int i=0, n = prefix.length();
         Trie* t = this;
         for (i=0;i<n;i++) {
             if (t->a[prefix[i]-'a'] != NULL) {
                 t = t->a[prefix[i]-'a'];
             }
             else { return false; }
         }
         return true;
    }
};

// DRIVER CODE - TESTER
int main () { 
 string word = "apple";
 string prefix = "app";
 Trie* obj = new Trie();
 obj->insert(word);
 cout<<obj->search("app")<<endl;
 cout<<obj->startsWith(prefix)<<endl<<endl;
 obj->insert("app");
 cout<<obj->search("app")<<endl;
 cout<<obj->startsWith(prefix)<<endl;
 
}