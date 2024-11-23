#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Difficulty : Easy

/* TWO POINTERS */
class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.length(), i = 0, j = n-1;
        unordered_map<char,int> vowels = {{'A',1},{'E',1},{'I',1},{'O',1},{'U',1},{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
        
        while (i<j) {
            
            while(i<n && vowels[s[i]] == 0) { i++; }
            while(j>=0 && vowels[s[j]] == 0) { j--; }
            
            if (i>=n || j<0 || i>j) { break; }
            
            swap(s[i],s[j]);
            
            i++; j--;
        }
        
        return s;
    }
};