#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/clumsy-factorial/
// Difficulty : Medium

/* SIMULATION - DO WHAT THEY TELL YOU TO DO, BUT IN A SIMPLE WAY */

/* 
    The clumsy factorial is a*b/c+d-e*f/g+h-i*j/k+l-m........, where a = a, b = (a-1), c = (a-2),.....k = 3, l = 2, p = 1 for starting with a = 13
    This can be expressed as (a*b/c) + d - (e*f/g) + h - (i*j/k) + l -(m........ which is a series of simple addition terms and composite subtractions terms.
    We can express them again as C1 + A1 - C2 + A2 - C3 + A3 - ......... where An represents add term and Cn represents composite subtraction term.
    In each iteration we compute one of these terms and get the clumsy factorial, rather than using more complex stack methods.
    We use mode variable to determine what term and how to do the calculation.
*/
class Solution {
public:
    int clumsy(int n) {

        if (n < 3) { return n; }

        int num = n, factorial = 2 * ((n * (n-1)) / (n-2));
        char mode = 'C';

        while (n >= 3) {
            if (mode == 'C') {
                factorial -= (n * (n-1)) / (n-2); 
                n -= 3;
                mode = 'A';
            }
            else {
                factorial += n;
                n--;
                mode = 'C';
            }
        }

        // if (mode == 'A') { factorial += n; n--; mode = 'C'; }
        // if (mode == 'C') {
        //     Intially,
        //     | if (n == 2) { factorial -= (n * (n-1)); } |
        //     | if (n == 1) { factorial -= n; }           |
        //     Reduced to,
        //     | if (n == 2) { factorial -= 2; }           |
        //     | if (n == 1) { factorial -= 1; }           |
        //     Reduced to,
        //     | factorial -= n;                           |
        // }

        // Finally reduced to,
        if (n > 0 and mode == 'A') { factorial += n--; }
        factorial -= n;
        
        return factorial;
    }
};