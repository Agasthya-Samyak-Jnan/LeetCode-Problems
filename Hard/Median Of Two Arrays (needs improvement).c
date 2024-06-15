#include<stdio.h>

//Link to the Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
//Difficulty: Hard

//Best Solution is O(log(m+n)) uses concept of BINARY PARTITIONING

// This Solution is O(m+n)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i=0,j=0;
    double a = 0,b = 0;
    
    while (i+j <= (nums1Size+nums2Size)/2 ) {
        
        a = b;
        
        if (i < nums1Size && j < nums2Size)
        {
         if ( nums1[i] < nums2[j]) { b = nums1[i]; i++; }
         else  { b = nums2[j]; j++;  }
        }
        
        else if (j < nums2Size) 
        {
          b = nums2[j]; j++;
        }
        
        else
        {
          b = nums1[i]; i++;  
        }
            
    }
    if ( (nums1Size+nums2Size) % 2 ) { return b; }
    else { return (a+b)/2 ; }
}