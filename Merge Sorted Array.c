#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy

// Time Complexity: O(n) 
void merge(int* a, int as, int m, int* b, int bs, int n) {
     
    int i=0,j=0, t[as];
    
    while (i<m || j<n) {
        if (i == m) { t[i+j] = b[j]; j++; continue; }
        if (j == n) { t[i+j] = a[i]; i++; continue; } 
        if (a[i] < b[j]) { t[i+j] = a[i]; i++; }
        else { t[i+j] = b[j]; j++; }
    }
    for (int i=0;i<as;i++) { a[i] = t[i]; }  
}