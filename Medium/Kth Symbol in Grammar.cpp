#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/k-th-symbol-in-grammar/
// Difficulty : Medium


/*
Example Of Grammar given in Question , Looks like below,

Given : Convert (0) in Current Row -> (0 1) in Next Row
        Convert (1) in Next Row -> (1 0) in Next Row

1 : 0
2 : 0 1
3 : 0 1 1 0
4 : 0 1 1 0 1 0 0 1
5 : 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
6 : 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1

Observe few things in the above pattern :

1. Every nth Row has Last 2^(n-2) elements obtained by Inverting First 2^(n-2) elements of same Row.
2. Each Number in a Row gives Two Numbers in Next Row.
3. The Even Position Number in current Row is Obtained by a Number that is at (Half) of that Position in previous Row and 
   is Complement of this Number.
   This is Because of the rule that they have given to convert 0 and 1 to Two Numbers in Next Row.
4. The Odd Position Number in current Row is Obtained by a Number that is at (Half+1) of that Position in previous Row and 
   is SAME as this Number.

IDEA : We Should do the Right Number of Flips on "0" to Obtain the Kth Number in Nth Row, Because, WE ALWAYS START FROM "0".

LOGIC : Start from Kth Position in Nth Row, Count the Number of FLIPS.

*/

/**/
class Solution {
public:
    int kthGrammar(int n, int k) {
        
        if (k==1) { return 0; } // Zero is Always the Starting Point.
        
        if (k%2 == 1) { return kthGrammar(n-1,(k+1)/2); } // Odd Position Number is Obtained from Same Number. DON'T FLIP.
        
        else { return !kthGrammar(n-1,k/2); } // Even Position Number is Obtained from Complement of Number. FLIP.
        
    }
};