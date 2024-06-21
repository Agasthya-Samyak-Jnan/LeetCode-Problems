#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/complement-of-base-10-integer/
// Difficulty : Easy

class Solution {
public:
    int bitwiseComplement(int n) {
        return n==0?1:n^((int)pow(2,(int)log2(n)+1)-1);
    }
};