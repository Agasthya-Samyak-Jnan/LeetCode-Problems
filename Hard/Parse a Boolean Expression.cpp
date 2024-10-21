#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/parsing-a-boolean-expression/
// Difficulty : Hard

/* STRING MANIPULATION + REPEATED FUNCTION-TO-FUNCTION CALLS */
class Solution {
public:
    string exp;
    int i = 0;
    
    bool solve_and () {
        bool ans = 1;
        i += 2;
        while (exp[i] != ')') {
            switch (exp[i]) {
                case ',' : { i++; break; }
                case '!' : { ans &= solve_not(); break; }
                case '|' : { ans &= solve_or(); break; }
                case '&' : { ans &= solve_and(); break; }
                default : { ans &= (exp[i] == 't'); i++; break; }
            }
        }
        i++;
        
        return ans;
    }
    
    bool solve_or () {
        bool ans = 0;
        i += 2;
        while (exp[i] != ')') {
            switch (exp[i]) {
                case ',' : { i++; break; }
                case '!' : { ans |= solve_not(); break; }
                case '|' : { ans |= solve_or(); break; }
                case '&' : { ans |= solve_and(); break; }
                default : { ans |= (exp[i] == 't'); i++; break; }
            }
        }
        i++;
        
        return ans;
    }
    
    bool solve_not () {
        bool ans;
        i += 2;
        switch (exp[i]) {
            case ',' : { i++; break; }
            case '!' : { ans = !solve_not(); break; }
            case '|' : { ans = !solve_or(); break; }
            case '&' : { ans = !solve_and(); break; }
            default : { ans = !(exp[i] == 't'); i++; break; }
        }
        i++;
        
        return ans;
    }
    
    bool solve () {
        if (exp[0] == '&') { return solve_and(); }
        if (exp[0] == '|') { return solve_or(); }
        return solve_not();
    }
    
    
    bool parseBoolExpr(string expression) {
        exp = expression;
        return solve();
    }
};