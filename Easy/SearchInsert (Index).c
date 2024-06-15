#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/search-insert-position/submissions/
//Difficulty: Easy

//Time Complexity: O(logN)
//Space Complexity: O(1)

int searchInsert(int* a, int n, int t) {
    int low = 0, high = n, mid;
    
    while (low<high) {
        mid = (low+high)/2;
        if (a[mid] == t) { return mid; }
        if (a[mid] > t) { high = mid; }
        else { low = mid+1; }
    }
    return (low+high)/2;
}
