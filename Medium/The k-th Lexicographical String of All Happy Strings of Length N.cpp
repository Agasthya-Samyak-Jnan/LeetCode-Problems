#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Difficulty : Medium

/* PRIORITY QUEUE + BACKTRACKING */
class Solution {
    public:
        priority_queue<string,vector<string>,greater<string>> pq;
        string happyString = "";
        int n;
    
        void solve () {
    
            if (happyString.length() == n) {
                pq.push(happyString);
                return;
            }
            
            unordered_set<char> letters = {'a','b','c'};
            if (!happyString.empty()) { letters.erase(happyString.back()); }
    
            for (char c : letters) {
                happyString += c;
                solve();
                happyString.pop_back();
            }
        
        }
    
        string getHappyString(int n, int k) {
        
            this->n = n;
    
            solve();
    
            while (k > 1 and !pq.empty()) { pq.pop(); k--; }
    
            return pq.empty() ? "" : pq.top();
        }
};

/* 
    ORDERED BACKTRACKING : ELIMINATE PRIORITY QUEUE BY EXPLORING HAPPY STRINGS IN LEXICOGRAPHICAL ORDER.
   (USE 'a', 'b', 'c' in order while building strings)
*/
class Solution {
    public:
        string happyString = "";
        int n,k;
    
        bool solve () {
    
            if (happyString.length() == n) {
                k--;
                return (k==0);
            }
            
            // LEXICOGRAPHICAL ORDERING USING ORDERED SET. Explore by adding smallest characters first.
            set<char> letters = {'a','b','c'};
            if (!happyString.empty()) { letters.erase(happyString.back()); }
    
            for (char c : letters) {
                happyString += c;
                if (solve()) { return true; }
                happyString.pop_back();
            }
    
            return false;
        }
    
        string getHappyString(int n, int k) {
        
            this->n = n;
            this->k = k;
    
            solve();
    
            return happyString;
        }
};

/* MORE OPTIMISED (SMALL DETAILS) ORDERED BACKTRACKING */

/* PASS BY VALUE BACKTRACKING - COMPRESSED SOLUTION */
class Solution {
    public:
    
        pair<bool,string> solve (string happyString, int n, int& k) {
    
            if (happyString.length() == n) { 
                if (--k == 0) { return {true,happyString}; }
                return {false,""};
            }
            
            vector<char> letters = {'a','b','c'};
            if (!happyString.empty()) { 
                letters.erase(letters.begin() + happyString.back()-'a'); 
            }
    
            for (char& c : letters) {
                    auto [found,res] = solve(happyString+c,n,k);
                    if (found) { return {true,res}; }
            }
    
            return {false,""};
        }
    
        string getHappyString(int n, int k) {
            return solve("",n,k).second;
        }
};

/* PASS BY REFERENCE BACKTRACKING */
class Solution {
    public:
        string happyString = "";
        int n,k;
    
        bool solve () {
    
            if (happyString.length() == n) { return (--k==0); }
            
            vector<char> letters = {'a','b','c'};
            if (!happyString.empty()) { 
                letters.erase(letters.begin() + happyString.back()-'a'); 
            }
    
            for (char& c : letters) {
                    happyString += c;
                    if (solve()) { return true; }
                    happyString.pop_back();
            }
    
            return false;
        }
    
        string getHappyString(int n, int k) {
        
            this->n = n;
            this->k = k;
    
            solve();
    
            return happyString;
        }
};