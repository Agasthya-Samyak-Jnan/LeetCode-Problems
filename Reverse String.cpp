#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/reverse-string/
// Difficulty : Easy

using namespace std;

// Using Iterators Over a Vector 
class Solution {
public:
    void reverseString(vector<char>& s) {
         auto it = s.begin(), jt = s.end()-1; char temp;
         while (it<jt) {
             temp = *it;
             *it = *jt;
             *jt = temp;
             it++; jt--;
         }
    }
};