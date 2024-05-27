#include<stdio.h>
#include<stdlib.h>

// Link to the Problem: https://leetcode.com/problems/binary-search/
// Difficulty: Easy

int search(int* a, int n, int key) {
    int low=0, high=n, mid;

    while (low < high) {
        mid = (low+high)/2;
        if (a[mid] == key) { return mid; }
        if (a[mid] > key) { high = mid; }
        else { low = mid + 1; }
    }
    return -1;
}

/*Recursive Binary Search

int search (int* a, int low, int high, int key) {
    if (a[(low+high)/2] == key) { return (low+high)/2; }
    if (low >= high) { return -1; }
    if (a[(low+high)/2] < key) { search(a, (low+high)/2 + 1, high, key); }
    else { search(a, low, (low+high)/2 , key); }
}
*/
