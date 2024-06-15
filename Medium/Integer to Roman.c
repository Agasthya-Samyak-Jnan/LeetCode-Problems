#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/integer-to-roman/
//Difficulty: Medium

char* intToRoman(int n) {
      
    int i=0, j=0;
    char* s = (char*)calloc(16,sizeof(char));
    
    //1000-3000
    j=0;
    
    while (j < n/1000) { s[i+j] = 'M'; j++; }
  
    i += j;
    n %= 1000;
    
    //100-900
    j=0;
    
    if (n/100 < 4) { while (j < n/100) { s[i+j] = 'C'; j++; } }
    else if (n/100 == 4) { s[i++] = 'C'; s[i++] = 'D'; }
    else if (n/100 == 5) { s[i++] = 'D'; }
    else if (n/100 < 9) { s[i++] = 'D'; while (j < (n/100)-5) { s[i+j] = 'C'; j++; } }
    else { s[i++] = 'C'; s[i++] = 'M'; }
    
    i += j;
    n %= 100;

    //10-90
    j=0;
    
    if (n/10 < 4) { while (j < n/10) { s[i+j] = 'X'; j++; } }
    else if (n/10 == 4) { s[i++] = 'X'; s[i++] = 'L'; }
    else if (n/10 == 5) { s[i++] = 'L'; }
    else if (n/10 < 9) { s[i++] = 'L'; while (j < (n/10)-5) { s[i+j] = 'X'; j++; } }
    else { s[i++] = 'X'; s[i++] = 'C'; }
    
    i += j;
    n %= 10;

    //1-9
    j=0;
    
    if (n < 4) { while (j < n) { s[i+j] = 'I'; j++; } }
    else if (n == 4) { s[i++] = 'I'; s[i++] = 'V'; }
    else if (n == 5) { s[i++] = 'V'; }
    else if (n < 9) { s[i++] = 'V'; while (j < (n-5) ) { s[i+j] = 'I'; j++; } }
    else { s[i++] = 'I'; s[i++] = 'X'; }

    i += j;
    
    return s;
}

int main () {

  printf("%s", intToRoman(3749));

  return 0;
}