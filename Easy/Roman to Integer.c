#include<stdio.h>
#include<stdlib.h>

//Link to the Problem: https://leetcode.com/problems/roman-to-integer/
//Difficulty: Easy

int romanToInt(char* s) {
    int i=0, x=0;
    while (1) {    
     switch (*(s+i)) {
            case 'I' : {if(*(s+i+1) == 'V') { x += 4; i++; }
                        else if (*(s+i+1) == 'X') { x += 9; i++; }
                        else { x += 1; }
                        break;}
            case 'V' : { x += 5; break; }
            case 'X' : { if(*(s+i+1) == 'L') { x += 40; i++; }
                        else if (*(s+i+1) == 'C') { x += 90; i++; }
                        else { x += 10; }
                        break;}
            case 'L' : { x += 50; break; }
            case 'C' : { if(*(s+i+1) == 'D') { x += 400; i++; }
                        else if (*(s+i+1) == 'M') { x += 900; i++; }
                        else { x += 100; }
                        break;}
            case 'D' : { x += 500; break; } 
            case 'M' : { x += 1000; break; }   
            default : return x;}
      i++;}} 