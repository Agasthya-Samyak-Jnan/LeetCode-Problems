#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Difficulty : Easy 

/* USING STACK */
class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        int max_size = 0;

        for (auto c : s) {
            if (c == '(') { st.push(c); max_size = max(max_size,(int)st.size()); }
            else if (c == ')') { st.pop(); }
        }

        return max_size;
    }
};

/* SPACE OPTIMIZED : YOU NECESSARILY DON'T NEED STACK TO TRACK MAXIMUM NUMBER OF OPEN PARENTHESES A CHARACTER COMES AFTER. JUST USE A SINGLE VARIABLE. */
class Solution {
public:
    int maxDepth(string s) {
        
        int open_parentheses = 0, max_size = 0;

        for (auto c : s) {
            if (c == '(') { open_parentheses++; max_size = max(max_size,open_parentheses); }
            else if (c == ')') { open_parentheses--; }
        }

        return max_size;
    }
};