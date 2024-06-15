#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/powx-n/
//Difficulty: Medium

double myPow(double x, int n) {
    
    if (n == 0) { return 1; }
    if (n == 1) { return x; }
    if (n == -1) { return 1/x; }
    
    if (n%2) { return x*myPow(x,n-1); }
    else {return myPow(x*x, n/2); }
    
}