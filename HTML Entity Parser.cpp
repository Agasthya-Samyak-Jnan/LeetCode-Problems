#include<bits/stdc++.h>
#include<unordered_map>

// Link to the Problem: https://leetcode.com/problems/html-entity-parser/
// Difficulty: Medium

using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    string entityParser(string text) {
        
        int i=0;
        string temp = "";
        string parsed = "";
        
        unordered_map<string,char> entity;
        entity["&quot"] = '"';
        entity["&apos"] = '\'';
        entity["&amp"] = '&';
        entity["&gt"] = '>';
        entity["&lt"] = '<';
        entity["&frasl"] = '/';
        
        while (text[i] != 0) {
            if (text[i] == '&') {
                while (text[i] != ';') {
                    temp += text[i]; 
                    i++; 
                    if (!text[i]) { parsed += temp; return parsed; }
                    if ( text[i] == '&') { parsed += temp; temp =""; }
                }
                auto it = entity.find(temp);
                if (it != entity.end()) { temp = entity.at(temp); }
                else { temp += ";"; }
                parsed += temp;
                temp = "";
            }
            else { parsed += text[i]; }
            i++;
        }
        return parsed;
    }
};