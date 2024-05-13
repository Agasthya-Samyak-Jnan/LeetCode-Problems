#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Link to the Problem: https://leetcode.com/problems/hamming-distance/
// Difficulty : Easy

 
int hammingDistance(int x, int y) {
    x ^= y;
    int i = 0;
    while(x){
        x = x & (x-1);
        i++;
    }
    return i;
}
