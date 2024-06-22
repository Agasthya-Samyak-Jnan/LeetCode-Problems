#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/convert-a-number-to-hexadecimal/
// Difficulty : Easy

class Solution {
public:
    string toHex(unsigned int num) {
        string hex;
        char H[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        if(num<0) { num = num^((int)pow(2,(int)log2(num)+1)-1); } //For Negative Numbers, Use Complement form.
        if(!num) { return "0"; } //For Zero, Return 0.
        
        while (num) {
            hex += H[num%16];
            num /= 16;
        }
        reverse(hex.begin(),hex.end()); // Reverse to get actual answer.
        
        return hex;
    }
};