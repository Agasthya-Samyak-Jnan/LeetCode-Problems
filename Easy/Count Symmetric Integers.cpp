#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/count-symmetric-integers/
// Difficulty : Easy

/* BRUTE FORCE */
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
    
            int symInts = 0;
    
            for (int num=low;num<=high;num++) {

                int n = log10(num) + 1;

                if (n%2 == 1) { continue; }

                vector<int> half(2,0);
                int temp = num;

                for (int i=0;i<2;i++) {

                    int k = n/2;
                    
                    while (k > 0) {
                        half[i] += temp%10;
                        temp /= 10;
                        k--;
                    }

                }

                symInts += (half[0] == half[1]);

            }
    
            return symInts;
        }
};