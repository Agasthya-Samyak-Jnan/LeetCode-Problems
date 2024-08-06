#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Difficulty : Medium 

class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.length();
        int mintaps = 0, keytaps = 0;
          vector<int> freq(26,0);
        
          for (int i=0;i<n;i++) { freq[word[i]-'a']++; }
        
          sort(freq.begin(),freq.end());
          
          for (int i=25;i>=0;i--) { 
             if (freq[i] != 0) { mintaps += ((keytaps/8)+1)*freq[i]; keytaps++; } 
          }
        
        
          return mintaps;
        
    }
};