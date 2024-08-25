#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/word-search/
// Difficulty : Medium

/* BACKTRACKING WITH DEPTH-FIRST SEARCH */
class Solution {
public:
    // Global stuffs to avoid frying your brain with Lots of parameters in each function.
    int m,n,w;
    vector<vector<char>> b;
    string word;
    
    bool dfs (int i, int j, int k) {
        // If Word is found, 'k' would be equal to Length of Word.
        if (k >= w) { return true; }
        
        // Out-Of-Bounds Indexing and Letter Mismatch does not Match Word.
        if (i<0 || j<0 || i>=m || j>=n || b[i][j] != word[k]) { return false; }

        int temp = b[i][j]; // Store the Letter Temporarily. We need this to backtrack and revert changes.
        b[i][j] = '.'; // Mark as Visited by changing letter to '.' to avoid revisiting(Infinite loop) .
        
        // Check if Up || Right || Down || Left Cell Letters Match the Word.
        bool found = dfs(i-1,j,k+1) || dfs(i,j+1,k+1) || dfs(i+1,j,k+1) || dfs(i,j-1,k+1);
        
        b[i][j] = temp; // Revert Changes to allow all paths - Backtrack to previous state.
        
        return found; // This will be true if and only if any of the path in any direction found the word.
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        // Initialise all Global Stuffs. (VERY IMPORTANT)
        b = board;  
        this->word = word;
        m = board.size(), n = board[0].size(), w = word.length();
        unordered_map<char,int> mp;
        
        // Count Frequency Of Letters in Board
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                mp[b[i][j]]++;
            }
        }
        // Count Frequency of Letters in Word. 
        // If "Word" HAS some letters more than that in "board" , word cannot be formed at all.
        for (int i=0;i<w;i++) {
            if (!mp[word[i]]) { return false; }
            mp[word[i]]--;
        }
        
        // If Letter Counts Match, Time to find if Word can be formed or not.
        // Find Starting Letter - all possible start points to search word.
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                    if (word[0] == b[i][j] && dfs(i,j,0)) { return true; }
            }
        }
        
        return false;
    }
};