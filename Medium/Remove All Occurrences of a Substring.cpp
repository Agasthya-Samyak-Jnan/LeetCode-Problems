#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Difficulty : Medium 

// SIMULATION
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            
            int m = part.length(),i,j;
            bool had_substr = true;
            string ans;
            
            while (had_substr) {
                had_substr = false;
                ans = ""; 
                i = 0;
                while (i<s.length()) {
                    j = 0;
                    while(j<m and i+j < s.length() and s[i+j] == part[j]) { j++; }
                    if (j == m) {  had_substr = true; ans += s.substr(i+j,s.length()-(i+j)+1); break; }
                    else { ans += s[i]; i++; }
                }
                // cout<<ans<<"\n";
                s = ans;
            }
    
            return s;
        }
};

// Using Library Functions (Abstraction)
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            while(s.length()>0 && s.length()>s.find(part)){
               s.erase(s.find(part),part.length());
            }
            return s;
        }
    };

// DRIVER CODE
int main() {

    Solution a;
    string s = "aabababa";
    string part = "aba";
    cout<<a.removeOccurrences(s,part);

}