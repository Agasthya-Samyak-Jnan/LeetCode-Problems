#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/optimal-partition-of-string/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
//Difficulty: Medium

int partitionString(char* s) {
    int a[26] = {0};
    int p = 1;    
    while(*s != 0) {
        if (a[*s-97] == p) { a[*s-97] = ++p; }
        else { a[*s-97] = p; }
        s++;
    }
    return p;     
}