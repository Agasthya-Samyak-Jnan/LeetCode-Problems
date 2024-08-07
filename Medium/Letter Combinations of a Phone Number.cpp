#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Difficulty : Medium


/* MAPPING KEYS AND THEN BACKTRACKING ON SET OF STRINGS FORMED USING EACH DIGIT KEY */
vector<string> letterCombinations(string digits) {
        
        if (digits == "") { return {}; }
        
        // Telephone Keys Mapping
        vector<vector<char>> mp = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        
        vector<string> ans = {""};
        int n = digits.length();
        
        for (auto i : digits) {       
            vector<string> temp;
            for (auto j : mp[i-'0']) {
                for (auto k : ans) {
                    temp.push_back(k+j);
                } 
            }
            ans = temp;   
        }
        return ans; 
}


int main () {
    
    vector<string> ans = letterCombinations("23");

    for (auto i : ans) {
        cout<<i<<",";
    }
    

    return 0;
}