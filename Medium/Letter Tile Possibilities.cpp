#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/letter-tile-possibilities/
// Difficulty : Medium

/* BACKTRACKING SOLUTION (ITERATIVE) - O(n!) */
class Solution {
    public:
        int numTilePossibilities(string t) {
            
            int n = t.length(), ANS = 0;
            unordered_multiset<char> tiles(t.begin(),t.end()), t_tiles;
            vector<string> ans = {""}, temp;
    
    
            for (int r=n;r>=1;r--) {
                temp.clear();
                for (string s : ans) {
                    unordered_multiset<char> t_tiles = tiles;
                    for (char cs : s) { 
                        auto it = t_tiles.find(cs);
                        if (it != t_tiles.end()) { t_tiles.erase(it); }
                    }
    
                    while (!t_tiles.empty()) {
                        char c = *t_tiles.begin();
                        temp.push_back(s+c);
                        t_tiles.erase(c);
                    }
                }
                ans = temp;
                ANS += temp.size();
            }
    
            return ANS;
        }
};