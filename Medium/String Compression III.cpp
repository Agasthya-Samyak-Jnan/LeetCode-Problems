#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/string-compression-iii/
// Difficulty : Medium 

class Solution {
public:
    string compressedString(string word) {
        
        char prev = word[0];
        int count = 0, n = word.length();
        string comp = "";
        
        for (int i=0;i<=n;i++) {
            
            if (prev != word[i] || count >= 9) {
                comp += ('0'+count);
                comp += prev;
                count = 1;
            } 
            else { count++; }
            
            prev = word[i];
        }
        
        return comp;
    }
};