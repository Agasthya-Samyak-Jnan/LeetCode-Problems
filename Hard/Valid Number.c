#include<stdio.h>
#include<stdbool.h>

// Link to the Problem: https://leetcode.com/problems/valid-number/
// Difficulty: Hard

/* True Cases: "005047e+6","2","0089","-0.1","+3.14","4.","-.9","2e10","-90E3","3e+7","+6e-1","53.5e93","-123.456e789" */
/* False Cases : "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", ".", "-", "6+2" */

/* ULTRA BRUTE FORCE : SUPER SAIYAN MODE (0ms Runtime) */
bool check (char s, bool* v) {
    return ( (s-43)>=0 && (s-43)<=58 ) && v[s-43]; 
}

bool isNumber(char* s) {
    bool e = 0, sym = 0, deci = 0, n = 0;
    //cached valid values
    bool v[59] = {}; int i=0;
    for (i=0;i<10;i++) { v[5+i] = 1; }
    v[0] = 1;
    v[2] = 1;
    v[3] = 1;
    v[26] = 1;
    v[58] = 1;
    /* 43 = + , 45 = -, 46 = . , 69 = E, 101 = e, 48-57 = 0-9 */
    i=0;
    if (!check(s[i],v) || s[i] == 69 || s[i] == 101) { return false; }
    if (strlen(s) == 1 ) { 
        if ((s[i] < 48 || s[i] > 57)) { return false; }
        else { return true; } 
    }
    if (s[i] == 46 && (s[i+1] < 48 || s[i+1] > 57)) { return false; }
    
    while (check(s[i],v)) {
        if (e && ((s[i] == 69 || s[i] == 101) || !n)) { return false; }
        if (deci && (s[i] == 46)) { return false; }
        if (e && !deci && s[i] == 46) { return false; }
        if (!e && sym && (s[i] == 43 || s[i] == 45)) { return false; }
    if (i != 0 && (s[i-1] != 69 && s[i-1] != 101) && (s[i] == 43 || s[i] == 45) && check(s[i-1],v) ) 
    { return false; }
        
        if (s[i] > 47 && s[i] < 58) { n = 1; }
        if (s[i] == 69 || s[i] == 101) { e = 1; }  
        if (s[i] == 43 || s[i] == 45) { sym = 1; }
        if (s[i] == 46) { deci = 1; }   
        i++;
    }
    if (!n) { return false; }
    if (s[i]==0) {
        if ( s[i-1] != 46 && (s[i-1] < 48 || s[i-1] > 57) ) { return false; }
        else { return true; }
    }
    return false; 
}
