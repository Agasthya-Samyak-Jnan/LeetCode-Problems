#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/number-of-senior-citizens/
// Difficulty : Easy

class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int seniors = 0;
        
        for (auto citizen : details) {
            seniors += ((citizen[11]-'0')*10 + (citizen[12]-'0')) > 60;
            
        }    
        return seniors;
    }
};