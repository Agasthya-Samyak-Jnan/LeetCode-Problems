#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
// Difficulty : Medium 

/* HASH TABLE + LOGICAL SIMULATION - DON'T SIMULATE BY INSERTING CHARS INTO STRING FOR REAL, JUST KEEP UPDATING FREQUENCY OF LETTERS WHILE SIMULATING. */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
        long long freq[26] = {0};
        long long len = 0, mod = 1e9 + 7;
        
        for (auto i : s) { freq[i-'a']++; len++; }
        
        for (int cnt=t;cnt>0;cnt--) {
            long long z = freq[25];
            for (int i=25;i>0;i--) { freq[i] = freq[i-1]; }
            freq[0] = 0;
            if (z != 0) {
                freq[0] = (freq[0]%mod + z%mod) % mod;
                freq[1] = (freq[1]%mod + z%mod) % mod;
                len = (len%mod + z%mod) % mod;
            }
        }
        
        return len;
    }
};

/* CREATIVE BUT INEFFICIENT QUEUE-BASED SIMPLE SOLUTION */
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        
            queue<char> q;

            for (auto c : s) { q.push(c); }

            for (int i=0;i<t;i++) {
                int l = q.size();
                for (int k=0;k<l;k++) {
                    char curr = q.front(); q.pop();
                    if (curr == 'z') {
                        q.push('a');
                        q.push('b');
                    } 
                    else { q.push(curr+1); }
                }
            }

        return q.size(); 
    }
};