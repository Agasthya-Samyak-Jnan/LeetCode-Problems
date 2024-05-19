#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/regular-expression-matching/
// Difficulty: Hard

/* Dynamic Programming Solution is Best Solution (0ms Runtime) */

/* Recursive Solution (220ms Runtime) */
bool isMatch(char* s, char* p) {
    if (!*p) { return !*s; }
    if (p[1] == '*') { return isMatch(s,p+2) || (s[0]==p[0]||(p[0]=='.'&& *s)) && isMatch(s+1,p); }
    return (p[0] == '.' || p[0] == s[0]) && *s && isMatch(s+1,p+1);
}