#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/day-of-the-year/
// Difficulty: Easy

// Brute Force : Time Complexity O(n) (0ms Runtime)
int dayOfYear(char* date) {
    int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d[3] = {}, i=0;
    int day = 0;
    while (*date) {
       if (*date == '-') { i++; date++; continue; }
       d[i] = d[i]*10 + (*date-'0');
       date++;
    }
    if (!(d[0]%4) && d[0] != 1900) { m[1]++; }
    for (i=1;i<d[1];i++) { day += m[i-1]; }
    return day+d[2];
}