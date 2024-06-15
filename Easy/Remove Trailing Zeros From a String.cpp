#include<bits/stdc++.h>
#include<vector>

// Link to the Problem : https://leetcode.com/problems/remove-trailing-zeros-from-a-string/
// Difficulty : Easy

using namespace std;

/* Time Complexity : O(n) */
class Solution {
public:
    string removeTrailingZeros(string a) {
           int i = a.length()-1;
           while (i > -1 && a[i] == '0') {i--;}
           return a.substr(0,i+1);
    }
};