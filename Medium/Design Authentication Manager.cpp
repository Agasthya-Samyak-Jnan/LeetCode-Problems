#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-authentication-manager/
// Difficulty : Medium 

/* HASH TABLE METHOD */
class AuthenticationManager {
public:
    unordered_map<string,int> tokens;
    int TTL;
    
    AuthenticationManager(int timeToLive) {
        TTL = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + TTL;
    }
    
    void renew(string tokenId, int currentTime) {
        if (tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + TTL;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto& token : tokens) {
            if (token.second > currentTime) { count++; }
        }
        return count;
    }
};