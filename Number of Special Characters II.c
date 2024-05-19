#include<stdio.h>

// Link to the Problem: https://leetcode.com/problems/count-the-number-of-special-characters-ii/
// Difficulty: Medium

/* My Initial Intuitive Solution but Complicated (15ms Runtime Average, 15ms Peak) */
int numberOfSpecialChars(char* word) {   
    int a[58] = {};
    int sp = 0, diff = 0; 
    while (*word) {    
          if (a[*word - 65] == -2) { sp--; a[*word - 65] = -1; word++; continue; }
          if (a[*word - 65] != -1) { a[*word - 65] = 1;
          if (*word - 65 > 31) { 
             if (a[*word - 97] == 1) { sp++; a[*word - 97] = -1; a[*word - 65] = -1; } 
          }
          else { 
            if (a[*word - 33] == 1) { sp++; a[*word - 33] = -2; }
            else { a[*word - 33] = -1; }
            a[*word - 65] = -1; 
          }
        }
        word++;
    }   
    return sp;
}

/* Simpler Solution (15ms Runtime Average, 9ms Peak)*/
int numberOfSpecialChars(char* word) {   
    int l[26];
    int u[26];
    int sp = 0,i=0;   
    for (i=0;i<26;i++) { l[i] = -1; u[i] = -1;}   
    i=0;
    while (*word != 0) {
        if (*word >= 'a') { l[*word-'a'] = i; }
        else if (u[*word-'A'] == -1) { u[*word-'A'] = i; }
        word++;
        i++;
    }  
    i=0;
    while (i<26) {
       if (l[i] != -1 && l[i] < u[i]) { sp++; } 
       i++;
    }   
    return sp;
}