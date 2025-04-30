#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Difficulty : Easy 

/* MATH :
    - Any Number can be expressed as num = (0 to 9 any OF these Numbers) * 10^(number of digits - 1)
    - Then, Number of Digits of a Number = (Maximum Power of 10 that Number contains) + 1 
    - log10 (also called Logarithm in Base 10) of Number gives Maximum Power of 10 it contains. log basically says Power to which base should be rised to give num.
*/
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
    
            int evenDigitNums = 0;
    
            for (auto num : nums) {
                if (((int)log10(num) + 1) % 2 == 0) { evenDigitNums++; }
            }
            
            return evenDigitNums;
        }
};