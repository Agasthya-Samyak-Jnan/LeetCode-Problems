#include<bits/stdc++.h>

using namespace std;

// Link to the Problem: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy

class Solution {
public:
    bool isValid(string s) {
        int i=0;
        unordered_map<char,char> parentheses;
        stack<char> stack;
        parentheses[')'] = '(';
        parentheses[']'] = '[';
        parentheses['}'] = '{';
        while (s[i]) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else if (!stack.empty() && stack.top() == parentheses[s[i]]) { stack.pop(); }
            else { return false; }
            i++;
        }
        if (!stack.empty() && !s[i]) { return false; }
        return true;
    }
};