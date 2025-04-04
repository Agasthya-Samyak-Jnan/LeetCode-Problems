#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/adding-spaces-to-a-string/
// Difficulty : Medium

// YOU MUST ALLOCATE NEW STRING FOR ANSWER , OTHERWISE IT WILL TAKE A LOT OF TIME.
// This question can be generalised into : "Adding Specific Character to a String at given positions."

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string ans = ""; // Answer String
        int i = 0;
        
        for (auto index : spaces) { // Go through all 'indices' where <space> has to be inserted.
            while (s[i] && i != index) { ans += s[i++]; } // Append Characters until 'index' where <space> has to be inserted.
            ans += " "; // Insert <space> at 'index'.
        }
        
        // After Adding All Spaces , Append remaining last characters to the string.
        while (s[i]) { ans += s[i++]; }
        
        return ans;
    }
};

/* PYTHON3 VERSION 

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = [] # Python String is Immutable. Hence a List is used for Answer.
        i = 0
        
        for index in spaces:   # Loop through every 'index' to insert all spaces.
            ans.append(s[i:index])   # Append Characters till 'index'.
            ans.append(" ")  # Add Space at 'index'.
            i = index # Move 'i' accordingly.
        
        ans.append(s[i:])  # Add remaining characters from 'i' till end of string.
        
        return ''.join(ans)  # Join all string elements of answer List into a single String.
*/