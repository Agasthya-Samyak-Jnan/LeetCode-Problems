#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/a-number-after-a-double-reversal/
// Difficulty : Easy

// Time Complexity: O(1)
bool isSameAfterReversals(int n) {
     return (n%10) || n<10;
}

/* Time Complexity: O(log10(N)) (Unnecessary Circus for such a simple problem)
bool isSameAfterReversals(int num) {
    int temp=num;
    int sum=0;
    while(temp!=0){
        int a=temp%10;
        sum=sum*10+a;
        temp=temp/10;
    }
    temp=sum;
    sum=0;
    while(temp!=0){
        int a=temp%10;
        sum=sum*10+a;
        temp=temp/10;
    }
    if(num==sum){
        return true;
    }
    return false;
}
*/