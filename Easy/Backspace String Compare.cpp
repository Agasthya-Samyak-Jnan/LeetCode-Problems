#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/backspace-string-compare/
// Difficulty : Easy 

/* USING STACK */
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st1, st2;

        for (auto c : s) {
            if (c != '#') { st1.push(c); }
            else { if (!st1.empty()) { st1.pop(); } }
        }

        for (auto c : t) {
            if (c != '#') { st2.push(c); }
            else { if (!st2.empty()) { st2.pop(); } }
        }

        while (!st1.empty() and !st2.empty()) {
            if (st1.top() == st2.top()) { st1.pop(); st2.pop(); }
            else { return false; }
        }

        return (st1.empty() and st2.empty());
    }
};

/* USING ONLY STRINGS */
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string st1 = "", st2 = "";

        for (auto c : s) {
            if (c != '#') { st1 += c; }
            else { if (st1.length()) { st1.pop_back(); } }
        }

        for (auto c : t) {
            if (c != '#') { st2 += c; }
            else { if (st2.length()) { st2.pop_back(); } }
        }

        return (st1 == st2);
    }
};