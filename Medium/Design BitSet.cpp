#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-bitset/
// Difficulty : Medium

/* TIME TO SPACE AND SPACE TO TIME TRADEOFFS IN DESIGN */
class Bitset {
public:
    string b, fb;
    int n, set_bits, unset_bits, isFlipped;
    
    Bitset(int size) {
        n = size;
        b = string(n,'0');
        fb = string(n,'1');
        set_bits = 0;
        isFlipped = 0;
    }
    
    void fix(int idx) {
        if (b[idx] == '0') { set_bits++; }
        b[idx] = '1'; 
        fb[idx] = '0';
    }
    
    void unfix(int idx) {
        if (b[idx] == '1') { set_bits--; }
        b[idx] = '0'; 
        fb[idx] = '1';
    }
    
    void flip() {
        isFlipped = !isFlipped;
        set_bits = n - set_bits;
        swap(b,fb);
    }
    
    bool all() { return set_bits == n; }
    
    bool one() { return set_bits; }
    
    int count() { return set_bits; }
    
    string toString() { return b; }
};