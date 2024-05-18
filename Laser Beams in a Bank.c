#include<stdio.h>

// Link to the Problem: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Difficulty: Medium

// Time Complexity: O(n^2) 
int numberOfBeams(char** b, int n) {    
    int prev=0, cur=0, sum=0;  
    for (register int i=0;i<n;i++) {
        for (register int j=0;b[i][j] != 0;j++) {
            if (b[i][j] == '1') { cur++; }
        }
        sum += prev*cur;
        if (cur) { prev = cur; cur = 0; }
    }
    return sum;
}