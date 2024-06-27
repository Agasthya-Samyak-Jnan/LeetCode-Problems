#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Difficulty : Medium


/* Time Complexity : O(n) - Evaluate Postfix Expression - Multi-digit Numbers Edition (Tokenised Expression) - Stack Method */
class Solution {
public:
    
    stack<int> s;

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        for (int i=0;i<n;i++) {
            if ((tokens[i][0]<58 && tokens[i][0]>47)||(tokens[i][0]=='-' && tokens[i].length()>1)) { 
                s.push(stoi(tokens[i])); 
            }
            else {
                int r = s.top(); s.pop();
                int l = s.top(); s.pop();
                int res = 0;
                switch ((char)tokens[i][0]) {
                    case '+' : { res = l+r; break; }
                    case '-' : { res = l-r; break; }
                    case '*' : { res = l*r; break; }
                    case '/' : { res = l/r; break; }
                    default : break;
                }
                //cout<<l<<" "<<tokens[i][0]<<" "<<r<<" = "<<res<<"\n"; For Debug Purposes
                s.push(res);
            }
        }
        return s.top();
    }
    
    // LOGIC OF STRING TO INTEGER CONVERTER IF YOU NEED
    // int string_To_Number (string num) {
    //        int r = 0, neg = 1, i = 0; 
    //        if (num[0] == '-') { neg = -1; i++; } // Negative Numbers
    //        while (num[i]) { r = r*10 + (num[i]-'0'); i++; } // Converter
    //        return r*neg;
    // }
};