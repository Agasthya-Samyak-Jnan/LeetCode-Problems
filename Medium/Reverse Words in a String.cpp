#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty : Medium

/*IN-PLACE REVERSAL OF WORDS using O(1) Space (0) , O(n) Time (n+n) */
string reverseWords(string s) {
        
        int n = s.length(),i=0;

        reverse(s.begin(),s.end());
        
        while (i<n) {

            while (s[i] == 32 && s[i+1] == 32) { s.erase(s.begin()+i+1); n--; }
            int j = s[i] == 32 ? ++i : i;
            while (s[i] != 32 && i < n) { i++; }
            reverse(s.begin()+j,s.begin()+i);

        }

        if (s[0] == 32) { s.erase(s.begin()); n--; }
        if (s[n-1] == 32) { s.erase(s.begin()+n-1); n--; }
        
        return s;  
}

/* Time Complexity : O(n) (n+2) , Space Complexity : O(n) (n) */
string reverseWords2(string s) {
        
        int n = s.length(),i=0;
        
        string ans = "";
        
        while (i<n) {   
            while (s[i] == 32) { i++; }
            int j = i;
            while (s[i] != 32 && i < n) { i++; }
            ans = s.substr(j,i-j) + " " + ans;
        }

        n = ans.length();

        if (ans[0] == 32) { ans.erase(ans.begin()); n--; }
        if (ans[n-1] == 32) { ans.erase(ans.begin()+n-1); }
        
        return ans;  
}

// TESTER CODE
int main () {

    cout<<reverseWords("        the sky   is     blue ")<<"\n";
    cout<<reverseWords2("        the sky   is     blue ");
    cout<<"-END";

    return 0;
}