#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/zigzag-conversion/
// Difficulty : Medium

/* RAIL FENCE CIPHER CONCEPT */
class Solution {
public:
    string convert(string plaintext, int key) {
        
        if (key == 1) { return plaintext; }
        
        int n = plaintext.length(), i = 0, j = 0;
        vector<vector<char>> a = vector<vector<char>>(key,vector<char>(n,'\0'));
        vector<int> dx = {1,1};
        string ciphertext;

        for (auto letter : plaintext) {
            a[i][j] = letter;
            if (i == 0) { dx = {1,1}; }
            if (i == key-1) { dx = {-1,1}; }
            i += dx[0]; j += dx[1];
        }

        for (auto row : a) {
            for (auto letter : row) {
                if (letter) { ciphertext += letter; }
            }
        }

        return ciphertext;
    }
};