#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/sum-of-two-integers/
// Difficulty : Medium

/* 
    DIGITAL SYSTEM DESIGN : K-Bit Full Adder Using Propogate And Carry Functions.
    
    pi = Propogate Function for 'i'th Bit addition.
    gi = Generate Function for 'i'th Bit addition.
    ci = Carry for 'i'th Bit addition.
    ai = 'i'th Bit of 'a'.
    bi = 'i'th Bit of 'b'.
    si = Sum of 'i'th Bits of 'a' and 'b'.
    cii = Carry for 'i+1'th Bit Addition.

    ans = Total Sum of 'a' and 'b' in Integer.

*/
class Solution {
public:
    int getSum(int a, int b) {
        
        bool pi,gi,ci = 0,ai,bi,si,cii;
        int ans = 0;
        
        for (int i=0;i<32;i++) {
            
            ai = (a>>i) & 1;
            bi = (b>>i) & 1;
            
            pi = ai^bi;
            gi = ai&bi;
            si = pi^ci;
            cii = gi | (pi&ci);
            
            if (si) { ans |= 1<<i; }
            else { ans &= ~(1<<i); }
            
            ci = cii;
            
        }
        
        return ans;
    }
};