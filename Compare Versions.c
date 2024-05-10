#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/compare-version-numbers/
//Difficulty: Medium

/* If Versions are Equal, return 0.
   If Version1 > Version2, return 1.
   If Version1 < Version2, return -1. */
   
int compareVersion(char* version1, char* version2) {
    
    int i=0,j=0,t1=0,t2=0;
    
    while (1) {
        
        if (*(version1+i) > 47) { t1 = t1*10 + (*(version1+i)-48); i++; }
        if (*(version2+j) > 47) { t2 = t2*10 + (*(version2+j)-48); j++; }
        
        if (*(version1+i) < 48 && *(version2+j) < 48) 
        {   
            if (t1 > t2) { return 1; }
            else if (t1 < t2) { return -1; }
            else if (*(version1+i) == 0 && *(version2+j) == 0) { return 0; }
            if (*(version1+i) != 0) { i++; }
            if (*(version2+j) != 0) { j++; }
            t1 = t2 = 0;
        }
    }
}

int main () {

    printf("%d\n", compareVersion("1.01", "1.001"));
    return 0;
}