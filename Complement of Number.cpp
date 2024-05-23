#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-complement/
// Difficulty : Easy

class Solution {
public:
    int findComplement(int n) {
        return n^(2*((1<<int(log2(n)))-1)|1);
    }
};
