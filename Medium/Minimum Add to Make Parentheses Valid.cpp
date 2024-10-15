#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Difficulty : Medium

/* STACK SOLUTION */
class Solution {
public:
    int minAddToMakeValid(string str) {
        
        stack<char> s;
        int moves = 0;
        
        for (auto i : str) {
            if (i == '(') { moves++; s.push(i); }
            else if (!s.empty()) { moves--; s.pop(); }
            else { moves++; }
        }
        
        return moves;
    }
};

/* WITHOUT STACK SOLUTION */
class Solution {
public:
    int minAddToMakeValid(string str) {
    
        int open_brackets = 0, moves = 0;
        
        for (auto i : str) {
            if (i == '(') { moves++; open_brackets++; }
            else if (open_brackets) { open_brackets--; moves--; }
            else { moves++; }
        }
        
        return moves;
    }
};