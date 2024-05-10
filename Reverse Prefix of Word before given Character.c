#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/reverse-prefix-of-word/
//Difficulty: Easy

char* reversePrefix(char* word, char ch) {
    int j = 0;
    for (int i=0; *(word+i) != 0; i++ ) {
        
        if (*(word+i) == ch) 
            {
              while (j < i) {        
                  ch = *(word+j);
                  *(word+j) = *(word+i);
                  *(word+i) = ch;
                  j++; 
                  i--;
              }
              return word;
            }
    }
    return word;
}