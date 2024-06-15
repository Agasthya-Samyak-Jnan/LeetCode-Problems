#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/fibonacci-number/
// Difficulty: Easy

/* WHILE LOOP PERFORMS BETTER THAN RECURSIVE ALOGRITHM IN THIS CASE */
int fib (int n) {
    if (!n) { return 0; }
    if (n == 1) { return 1; }
    int i=0, j=1, sum=0;
    while (n>1) {
        sum = i + j;
        i = j;
        j = sum;
        n--;
    }
    return sum;
}