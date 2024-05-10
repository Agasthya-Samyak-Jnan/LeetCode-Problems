#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/the-kth-factor-of-n/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
//Difficulty: Medium

int kthFactor(int n, int k) {
    
    int i=1;
    
    while (k != 0) 
    {
     if (n%i == 0) { k--; }
     if (i > n) { return -1; }
     i++;
    }
    return i-1;
}