#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/longest-common-prefix/
//Difficulty: Easy

char* longestCommonPrefix(char** strs, int strsSize) {
    
    int i=0,j=0,k=0; 
    
    char* str = (char*)calloc(150,sizeof(char));
    
    for (j=0; *(*(strs)+j) != 0;j++) {
        
         for (i=0; i < strsSize; i++) {
             
             if ( *(*(strs)+j) == *(*(strs+i)+j) ) {}
             else { *(str+k) = '\0'; return str; }
         }
        
         *(str+k) = *(*(strs)+j); k++;
    } 
                              
    *(str+k) = '\0';
    return str;
}

int main () {

char* strs[3] = {"agasthya", "asamyak", "ajnan"} ;

printf("%s", longestCommonPrefix(strs, 3));
    return 0; 
}