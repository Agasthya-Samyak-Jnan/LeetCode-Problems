#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/decode-string/
// Difficulty : Medium 

/* STACK - PARSING STRING BY RULES TYPE OF PROBLEMS */
class Solution {
public:
    string decodeString(string s) {
        
        stack<int> nums;
        stack<string> strs;
        int i = 0, n = s.length(), count;
        string temp,t,ans;
        
        while (i<n) {
            // Parsing Repetition Count Numbers, 
            if (isdigit(s[i])) {
                temp = "";
                while (isdigit(s[i]) && i<n) { temp += s[i++]; }
                nums.push(stoi(temp));
            }
            // Enter inside a nested String,
            else if (s[i] == '[') { 
                strs.push("["); 
                i++; 
            }
            // Parsing Strings to be repeated,
            else if (isalpha(s[i])) {
                temp = "";
                while (isalpha(s[i]) && i<n) { temp += s[i++]; }
                strs.push(temp);
            }
            // Come out of Current Nested String by converting it to normal String and then push it on stack.
            else {
                temp = ""; t = "";
                count = nums.top(); nums.pop();
                
                while (strs.top() != "[") {
                    temp = strs.top() + temp;
                    strs.pop();
                }
                strs.pop();
                
                while (count) { t += temp; count--; }
                strs.push(t);
                i++;
            }
            
        }
    
        while (!strs.empty()) { 
            ans = strs.top() + ans; 
            strs.pop(); 
        }
        
        return ans;
    }
};
