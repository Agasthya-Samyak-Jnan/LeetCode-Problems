#include<stdio.h>

// Link to the Problem: https://leetcode.com/problems/count-the-number-of-special-characters-i/ 
// Difficulty: Easy

int numberOfSpecialChars(char* word) {   
    // Hash Table to Keep Previously Occured Letters in Memory
    int a[58] = {};
    int sp = 0;   
    // Loop Through String
    while (*word) {       
        // If a letter has been already recognised as "Special", do not check it again. (Rule)
        if (a[*word - 65] != -1) {
         // Memorize the letter 
         a[*word - 65] = 1;
         // If its in range (a-z) (97-122)
         if (*word - 65 > 31) { 
            // Check if capital variant is present or not
            if (a[*word - 97] == 1) { 
                sp++; 
                // Recognised as "Special" indicator in Table
                a[*word - 97] = -1;
                a[*word - 65] = -1;
            } 
         }
         // If its in range (A-Z) (65-91) 
         else { 
            // Check if small variant is present or not
            if (a[*word - 33] == 1) { 
                sp++; 
                // Recognised as "Special" indicator in Table
                a[*word - 33] = -1;
                a[*word - 65] = -1;
            } 
         }
        }
        word++;
    }
    return sp;
}