#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/add-strings/
// Difficulty : Easy

/* using HASH TABLES in 2 ways AND OPERATING on STRINGS */
class Solution {
public:
    bool wordPattern(string p, string s) {

        int np = p.length(), ns = s.length(), ip = 0 , is = 0;
        string temp = "";
        unordered_map<char,string> mp_p2w;
        unordered_map<string,char> mp_w2p;

        while (is < ns and ip < np) {
            if (s[is] == ' ') {
                if (mp_p2w[p[ip]] == "" and mp_w2p[temp] == 0) { 
                    mp_p2w[p[ip]] = temp;  
                    mp_w2p[temp] = p[ip]; 
                }
                else if (mp_p2w[p[ip]] != temp) { return false; }
                ip++;
                temp = "";
            }
            else { temp += s[is]; }
            is++;
        }

        if (mp_p2w[p[ip]] != "" and mp_p2w[p[ip]] != temp) { return false; }
        if (mp_w2p[temp] and mp_w2p[temp] != p[ip]) { return false; }
        ip++;
        return (is >= ns) and (ip >= np);
    }
};