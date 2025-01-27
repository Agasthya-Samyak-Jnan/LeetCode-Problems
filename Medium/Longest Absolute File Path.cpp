#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/longest-absolute-file-path/
// Difficulty : Medium

/* STRING + STACK : DEPTH-FIRST SEARCH - CHECK ALL POSSIBLE PATHS AND COMPARE THOSE THAT END WITH A FILE, NOT A DIRECTORY. */
/* ITERATIVE APPROACH USING STACK */
class Solution {
public:
    int lengthLongestPath(string s) {
        
        stack<int> st;
        int curr_len = 0, prev_level = 0, curr_level, max_len = 0;
        bool is_File = false;
        st.push(0);
        
        for (int i=0;s[i];i++) {
            
            if (s[i] == '\n') {
                
                i++;
                curr_level = 0;
                while (s[i] and s[i] == '\t') { i++; curr_level++; }
                       
                if (curr_level > prev_level) {
                    st.push(curr_len+st.top()+1);
                }
                else { 
                    if (is_File) { max_len = max(max_len,st.top()+curr_len); }
                    int level_diff = prev_level - curr_level;
                    while (level_diff) { st.pop(); level_diff--; }
                }
                
                curr_len = 0;
                prev_level = curr_level;
                is_File = false;
            }
            
            if (s[i] == '.') { is_File = true; }
                       
            curr_len++;
        }
                       
        if (is_File) { max_len = max(max_len,st.top()+curr_len); }
                       
        return max_len;
    }
};