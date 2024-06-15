#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/container-with-most-water/
//Difficulty: Medium

//Hint: Use two pointers at the beginning and at the end.

int maxArea(int* height, int heightSize) {
    
    int i=0,j=heightSize-1, maxarea = 0;
    
    while (i != j) {
            
     if (height[i]<height[j]) 
     {
      if (height[i]*(j-i) > maxarea) { maxarea = height[i]*(j-i); }
      else { i++; }
     } 
     
     else 
     {
      if (height[j]*(j-i) > maxarea) { maxarea = height[j]*(j-i); }
      else { j--; } 
     } 
    }       
    return maxarea;
}