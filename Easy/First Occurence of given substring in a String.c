#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
//Difficulty: Easy

int strStr(char* haystack, char* needle) {
    
    int temp=0,i;
    
    for ( i=0; *(haystack+i) != 0; i++) {
        
        if (haystack[i] == needle[0]) 
        { 
            temp = i; i =0;
            
            while (*(needle+i) != 0) 
            {    
            if (*(haystack+i+temp) == 0)  { return -1; }    
            if (*(haystack+i+temp) != *(needle+i))  { break; } 
            i++;   
            }
            
            if (*(needle+i) == 0) { return temp; }
            else { i = temp; }
        }
    }
    return -1;
}

int main () {

    char haystack[4] = "aaa\0";
    char needle[5] = "aaaa\0";
    printf("%d\n", strStr(haystack, needle));

    return 0;
}