#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Link to the Problem: https://leetcode.com/problems/number-of-1-bits/
// Difficulty : Easy

// Find Number of 1s in binary representation of given number, also called Hamming Weight.

// Time Complexity: O(logN)
int hammingWeight(int a) {
    int n = log2(a);
    int i = 0;
    while (n > -1) {
        if (1 & a>>n) {i++;}
        n--;
    }
    return i;
}

// Alternate Simpler Way : O(logN)
int hammingWeight(int n) {
    int i = 0;

    while(n){
        n = n & (n-1);
        i++;
    }
    return i;
}

// Simplest and most Intuitive Way
int hammingWeight(int n) {
        
        int weight = 0;
        
        while (n) {
            weight += n%2;
            n /= 2;
        }
        
        return weight;
}


// Simplest and most concise Way
int hammingWeight(int n) {
    return n ? (n&1) + hammingWeight(n>>1) : 0;
}

