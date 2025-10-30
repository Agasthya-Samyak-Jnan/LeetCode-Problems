#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/can-place-flowers/
// Difficulty : Easy  

/* COUNTING */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int zeroes = 1;

        for (auto bed : flowerbed) {
            if (bed == 1) { 
                n -= (zeroes-1)/2; 
                zeroes = 0; 
            }
            else { zeroes++; }
        }

        n -= (zeroes/2); 

        return (n<=0);
    }
};