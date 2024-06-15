#include<stdio.h>
#include<stdbool.h>

//Link to the Problem: https://leetcode.com/problems/search-a-2d-matrix/
//Difficulty: Medium

//Time Complexity: O(log(m*n))

bool searchMatrix(int** matrix, int m, int* n, int target) {
    
     int low = 0;
     int high =(m)*(*n) - 1;
     int mid = (low+high)/2;
     
     while (low <= high) 
     {   
        mid = (low + high) / 2 ;
        if ( *(*(matrix + (mid/(*n))) + (mid%(*n))) == target) { return true; }
        if (low == high) { return false; }
        if ( *(*(matrix + (mid/(*n))) + (mid%(*n))) < target ) { low = mid + 1 ; }
        else { high = mid; }
     }  
     return false; 
}