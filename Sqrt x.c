#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/sqrtx/
//Difficulty: Easy

// O(logN) Time Complexity 

int mySqrt(int x) {
    
    long int low=2, high=x, mid;
    
    if (x == 0) { return 0; }
    while (low < high) 
    {   
        mid = (low+high)/2;
        if (mid*mid == x) { return mid; }
        if (mid*mid > x){ high = mid; }
        else {low = mid+1; }
    }
    return low-1;
}

/* // O(sqrt(n)) Time Complexity 
    int mySqrt (int x) {
        int i=0;
        while (i*i <= x) { i++; }
        return i-1;
}
*/

int main () {

    printf("%d", mySqrt(19));
    return 0;
}