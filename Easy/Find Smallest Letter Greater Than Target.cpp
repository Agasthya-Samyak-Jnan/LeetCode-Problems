#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Difficulty : Easy 

/* BINARY SEARCH */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size(), low = 0, high = n-1, mid;

        while (low < high) {
            mid = (low+high)/2;
            if (letters[mid] <= target) { low = mid+1; }
            else { high = mid; }
        }

        return letters[high] > target ? letters[high] : letters[0];
    }
};