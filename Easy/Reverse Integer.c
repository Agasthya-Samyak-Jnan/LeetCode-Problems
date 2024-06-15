#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/reverse-integer/
//Difficulty: Medium

int reverse(int x){

    long r = 0; 
    if ( x > 2147483648 || x < -2147483647) { return 0; }
    
    while ( x != 0) {
        if (x > 0) { r = (r*10) + (x % 10); }
        else { r = (r*10) + (x%(-10)); }
        x /= 10;
        if ( r > 2147483648 || r < -2147483647) { return 0; }
    }
    return r;
}