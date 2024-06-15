#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/length-of-last-word/submissions/
//Difficulty: Easy

//Time Complexity: O(n)
//Space Complexity: O(1)

int lengthOfLastWord(char* s) {
    int i=0,l=0,c=0;
    while (s[i] != 0) {
        if (i != 0 && s[i] == 32 && s[i-1] != 32) { c=l; l=0; }
        else if (s[i] != 32) { l++; }
        i++;
    }
    if (l != 0) { c=l; }
    return c;
}
