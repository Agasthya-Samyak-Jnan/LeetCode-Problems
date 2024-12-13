#include<bits/stdc++.h>

// Link to the Problem : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty : Medium

using namespace std;

/* Time Complexity: O(s.length()) -> O(n) */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
     int i=0,j=0,max=0; short a[255] = {0};
    
     while (s[j]) {
        if (!a[s[j]]) { 
            a[s[j]] = 1; 
            j++;
            if (max < (j-i)) { max = j-i; }
        }
        else {
            while (a[s[j]]) {
                a[s[i]] = 0; i++;
            }
            a[s[j]] = 1; j++; 
        }
    }
    return max; 
   }
};

/* PYTHON3 VERSION

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        maxlen = 0
        n = len(s)
        i = 0
        j = 0
        found = [0]*256
        
        while j < n :
            if found[ord(s[j])] == 0 :
                found[ord(s[j])] = 1
                maxlen = max(maxlen,j-i+1)
                j+= 1
            else :
                while found[ord(s[j])] == 1 :
                    found[ord(s[i])] = 0 
                    i += 1
                found[ord(s[j])] = 1
                j += 1
        
        
        return maxlen
*/