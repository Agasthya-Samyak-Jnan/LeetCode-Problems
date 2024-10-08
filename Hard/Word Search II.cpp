#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/word-search-ii/
// Difficulty : Hard


/* IF YOU WANT TO OPTIMIZE STORAGE FOR LARGE INPUTS - WORD NOT INCLUDED IN TRIE */
/* Custom Written Trie Data Structure */ 
class Trie {
public:
    Trie* a[26] = {0};
    int letters;
    bool is_Word;
        
    Trie() {
       is_Word = false;
       letters = 0;
    }
    
    void insert(string word) {
        
         int n = word.length();
         Trie* t = this,*newnode;
         for (auto w : word) {
             if (t->a[w-'a'] == nullptr) { t->a[w-'a'] = new Trie(); t->letters++; }
             t = t->a[w-'a'];
         }
        
         if(!t->is_Word) { t->letters++; t->is_Word = true; }
    }
};

class Solution {
public:
    
    vector<vector<char>> b;
    vector<string> ans;
    string word;
    int m,n;
    Trie *T;
    
    // THE BACKTRACKING MACHINE - DFS
    void solve (int i, int j, Trie* t) {
                
        // Out-of-bounds access OR Word Letter Mismatch. DO NOT CONTINUE.
        if (b[i][j] == '.' || !t->a[b[i][j]-'a']) { return; }
        
        // Move inside Trie.
        t = t->a[b[i][j]-'a'];
        
        // Marking Visited Cells to avoid Infinite Loops. (DFS)
        // Creating Word formed TEMPORARILY.
        /* Keep in Memory the letter that got marked to keep the board intact 
           throughout the full search. */
        word += b[i][j];
        char temp = b[i][j];
        b[i][j] = '.';
        
        // When Word is Found.
        if (t->is_Word) { 
            ans.push_back(word);
            t->is_Word = false;
        }
        
        // Check if word can be formed while going....
        if (j>0) { solve(i,j-1,t); } // Left
        if (i>0) { solve(i-1,j,t); } // Up
        if (j<n-1) { solve(i,j+1,t); } // Right
        if (i<m-1) { solve(i+1,j,t); } // Down
        
        // Revert Changes to letter that was marked as 'visited' to allow other Word Searches.
        // Ending this search path , hence revert changes made to 'word'.
        b[i][j] = temp;
        word.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // Initializations
        m = board.size(); n = board[0].size();
        b = board;
        string word = "";
        
        // Load all words into Trie.
        T = new Trie(); 
        for (auto word : words) { T->insert(word); }
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                solve(i,j,T);
            }
        }
        
        return ans;
    }
};


/* Custom Written Trie Data Structure */ 
class Trie {
public:
    Trie* a[26] = {0};
    int letters;
    bool is_Word;
    string word;
        
    Trie() {
       is_Word = false;
       letters = 0;
    }
    
    void insert(string word) {
        
         int n = word.length();
         Trie* t = this,*newnode;
         for (auto w : word) {
             if (t->a[w-'a'] == nullptr) { t->a[w-'a'] = new Trie(); t->letters++; }
             t = t->a[w-'a'];
         }
         t->word = word;
         if(!t->is_Word) { t->letters++; t->is_Word = true; }
    }
    
};

/* IF YOU TO OPTIMIZE TIME FOR LARGE INPUTS : WORD INCLUDED IN TRIE ITSELF. */
class Solution {
public:
    
    vector<vector<char>> b;
    vector<string> ans;
    int m,n;
    Trie *T;
    
    // THE BACKTRACKING MACHINE - DFS
    void solve (int i, int j, Trie* t) {
                
        // Out-of-bounds access OR Word Letter Mismatch. DO NOT CONTINUE.
        if (b[i][j] == '.' || !t->a[b[i][j]-'a']) { return; }

        // Move inside Trie.
        t = t->a[b[i][j]-'a'];
        
        // When Word is Found.
        if (t->is_Word) { 
            ans.push_back(t->word);
            t->is_Word = false;
        }
        
        // Marking Visited Cells to avoid Infinite Loops. (DFS)
        /* Keep in Memory the letter that got marked to keep the board intact 
           throughout the full search. */
        char temp = b[i][j];
        b[i][j] = '.';
        
        // Check if word can be formed while going....
        if (j>0) { solve(i,j-1,t); } // Left
        if (i>0) { solve(i-1,j,t); } // Up
        if (j<n-1) { solve(i,j+1,t); } // Right
        if (i<m-1) { solve(i+1,j,t); } // Down
        
        // Revert Changes to letter that was marked as 'visited' to allow other Word Searches.
        b[i][j] = temp;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // Initializations
        m = board.size(); n = board[0].size();
        b = board;
        
        // Load all words into Trie.
        T = new Trie(); 
        for (auto word : words) { T->insert(word); }
        
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                solve(i,j,T);
            }
        }
        
        return ans;
    }
};