#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/special-positions-in-a-binary-matrix/
//Difficulty: Easy

//Time Complexity: O(m*n)

int numSpecial(int** a, int m, int* n) {
    int row[m];  for (int i=0;i<m;i++) { row[i] = 0; }
    int col[*(n)];  for (int i=0;i<(*n);i++) { col[i] = 0; }
    int k = 0;
    
    for(int i=0;i<m;i++) {
        for (int j=0;j<(*n);j++) {
            if (a[i][j] == 1) 
            {   
                row[i] += 1; 
                col[j] += 1; 
            }
        }
    }
  
    for(int i=0;i<m;i++) {
        for (int j=0;j<(*n);j++) { 
            if(a[i][j] == 1 && (row[i] == 1 && col[j] == 1)) { k++; }
        }
    }
    
    return k;
}