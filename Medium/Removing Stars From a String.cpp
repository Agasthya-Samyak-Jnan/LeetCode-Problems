#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/removing-stars-from-a-string/
// Difficulty : Medium 

/* USING STACK - MEMORY LIMIT EXCEEDED */
class Solution {
    public:
        string removeStars(string s) {
    
            stack<char> st;
            string ans  = "";
    
            for (char c : s) {
                if (c != '*') { st.push(c); }
                else { st.pop(); }
            }
    
            while (!st.empty()) {
                ans = st.top() + ans;
                st.pop();
            }
    
            
            return ans;
        }
};


/* IF YOU THINK CAREFULLY - STACK IS NOT NEEDED - OPTIMIZATION */
class Solution {
    public:
        string removeStars(string s) {
    
            string ans  = "";
    
            for (char c : s) {
                if (c != '*') { ans += c; }
                else { ans.pop_back(); }
            }
        
            return ans;
        }
};