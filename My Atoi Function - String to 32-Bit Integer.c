#include<stdio.h>
#include<limits.h>

//Link to the Problem: https://leetcode.com/problems/string-to-integer-atoi/
//Difficulty: Medium

int myAtoi(char* s) {
    
    int plus = 0, minus = 0, i = 0; long number = 0;
    
    while ( *(s+i) == '+' || *(s+i) == '-' || *(s+i) == 32)  {
        if (*(s+i) == '-') { minus += 1;}
        if (*(s+i) == '+') { plus += 1;}
        if ( (plus || minus) && *(s+i) == 32) { return 0; }
        if (plus > 1 || minus > 1) { return 0; }
        i++;
    }  
    
    while (*(s+i) != 0) {
        if (*(s+i) >= '0' && *(s+i) <= '9') { number = number*10 + (*(s+i)-48); }
        else { break; }
        if (number > INT_MAX) { 
            if (minus) { return -INT_MAX-1;}
            else { return INT_MAX; }        
        }
        i++;
    }
    
    if (plus & minus) { return 0; }
    if (minus) { return -number; }
    else { return number; }
}